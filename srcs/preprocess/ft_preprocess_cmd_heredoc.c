/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_cmd_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:15:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/16 16:04:35 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocess_heredoc.h"

/*
		Put commands from input inside my_data. Also handle here_doc
*/
void	ft_preprocess_cmd_heredoc(int argc, char **argv, t_data *my_data)
{
	char	**commands;
	int		i;

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
	my_data->infile = "srcs/tmp/tmp.txt";
	my_data->num_commands = i;
}

/*
		Save the data from here_doc inside temporary created file
	
	input:
		my_data - is my data
		delimiter - is delimiter for here_doc
*/
static void	ft_get_here_doc(t_data *my_data, char *delimiter)
{
	char	*line;

	delimiter = ft_strjoin(delimiter, "\n");
	if (!delimiter)
		ft_error_clean_exit(my_data);
	my_data->heredoc_fd = open("srcs/tmp/tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (my_data->heredoc_fd == -1)
		ft_perror_clean_exit(my_data, "Temporary file for here_doc failed");
	line = get_next_line(0, 0);
	while (line && ft_strcmp(line, delimiter) != 0)
	{
		ft_putstr_fd(line, my_data->heredoc_fd);
		free(line);
		line = get_next_line(0, 0);
	}
	free(delimiter);
	free(line);
	get_next_line(0, 1);
	close(my_data->heredoc_fd);
}
