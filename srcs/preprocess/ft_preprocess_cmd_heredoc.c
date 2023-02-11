/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_cmd_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:15:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/11 15:47:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocess_heredoc.h"

void    ft_preprocess_here_doc(int argc, char **argv, t_data *my_data)
{
    char    **commands;
    int i;

    ft_get_here_doc(my_data, argv[2]);
    commands = (char **)malloc(sizeof(char *) * (argc - 4 + 1));
    if (!commands)
        ft_error_clean_exit(my_data);
    i = 0;
    while (i < argc - 4)
    {
        commands[i] = argv[i + 3];
        i++;
    }
    commands[i] = NULL;
	my_data->commands = commands;
    my_data->infile = "tmp.txt";
    my_data->num_commands = i;
}

static void    ft_get_here_doc(t_data *my_data, char *delimiter)
{
	char	*s;

	s = NULL;
    delimiter = ft_strjoin(delimiter, "\n");
    if (!delimiter)
        ft_error_clean_exit(my_data);
	my_data->heredoc_fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (my_data->heredoc_fd == -1)
        ft_perror_clean_exit(my_data, "Temporary file for here_doc");
	while (1)
	{
		s = get_next_line(0, 0);
		if (!s || !ft_strcmp(s, delimiter))
			break ;
		ft_putstr_fd(s, my_data->heredoc_fd);
		free(s);
	}
    free(delimiter);
	free(s);
	get_next_line(0, 1);
	close(my_data->heredoc_fd);
	return (0);
}
