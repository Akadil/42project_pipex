/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:29:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/09 14:21:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_data.h"
#include <fcntl.h>
#include <stdio.h>

// The function to check all preprocesses. Like check for 
void    ft_preprocessing(int argc, char **argv, char **env, t_data *my_data)
{
    int i;

    if (argc < 6)
        exit(1); // I have to free the my_data and only then exit
    if (!env || !env[0])
        exit(1);
    my_data->env = env;
    if (ft_strcmp(argv[1], "here_doc") == 0)
        ft_preprocess_here_doc(argc, argv, my_data);
    else
        ft_preprocess_normal(argc, argv, my_data);
    my_data->outfile = argv[argc - 1];
}

int	get_here_doc(t_data *my_data, char *delimiter)
{
	char	*s;

	s = NULL;
	my_data->heredoc_fd = open("tmp.txt", O_RDWR | O_CREAT, 0644);
	while (1)
	{
		s = get_next_line(0, 0);
		if (!s || !ft_strcmp(s, delimiter))
			break ;
		ft_putstr_fd(s, my_data->heredoc_fd);
		free(s);
	}
	free(s);
	get_next_line(0, 1);
	close(my_data->heredoc_fd);
	return (0);
}

void    ft_preprocess_here_dock(int argc, char **argv, t_data *my_data)
{
    char    **commands;
    int i;

    if (get_here_doc(my_data, argv[2]) != 0)
        return ;
    commands = (char *)malloc(sizeof(char *) * (argc - 3 + 1));
    i = 0;
    while (i < argc - 3)
    {
        commands[i] = argv[i + 2];
        i++;
    }
    commands[i] = NULL;
    my_data->infile = "tmp.txt";
    
    my_data->num_commands = i;
}

void    ft_preprocess_normal(int argc, char **argv, t_data *my_data)
{
    char    **commands;
    int i;

    commands = (char *)malloc(sizeof(char *) * (argc - 3 + 1));
    i = 0;
    while (i < argc - 3)
    {
        commands[i] = argv[i + 2];
        i++;
    }
    commands[i] = NULL;
    my_data->num_commands = i;
    my_data->infile = argv[1];
    my_data->outfile = argv[argc - 1];
    my_data->heredoc_fd = -1;
}
