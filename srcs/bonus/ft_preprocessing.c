/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:29:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/09 17:57:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int	get_here_doc(t_data *my_data, char *delimiter);
void    ft_preprocess_here_doc(int argc, char **argv, t_data *my_data);
void    ft_preprocess_normal(int argc, char **argv, t_data *my_data);
void	ft_free_and_exit(t_data *my_data);

void    ft_preprocessing(int argc, char **argv, char **env, t_data *my_data)
{
    if (argc < 5 || !env || !env[0])
        ft_free_and_exit(my_data);
    my_data->env = env;
    if (ft_strcmp(argv[1], "here_doc") == 0)
        ft_preprocess_here_doc(argc, argv, my_data);
    else
        ft_preprocess_normal(argc, argv, my_data);
    my_data->pipe_fd[0] = -1;
    my_data->pipe_fd[1] = -1;
    my_data->prev_fd = -1;
    my_data->outfile = argv[argc - 1];
}

void    ft_preprocess_here_doc(int argc, char **argv, t_data *my_data)
{
    char    **commands;
    int i;

    if (get_here_doc(my_data, argv[2]) != 0)
        return ;
    commands = (char **)malloc(sizeof(char *) * (argc - 4 + 1));
    if (!commands)
    {
        ft_printf("%s\n", strerror(errno));
        free (my_data);
        exit(-1);
    }
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

void    ft_preprocess_normal(int argc, char **argv, t_data *my_data)
{
    char    **commands;
    int i;

    commands = (char **)malloc(sizeof(char *) * (argc - 3 + 1));
    if (!commands)
    {
        ft_printf("%s\n", strerror(errno));
        free (my_data);
        exit(-1);
    }
    i = 0;
    while (i < argc - 3)
    {
        commands[i] = argv[i + 2];
        i++;
    }
    commands[i] = NULL;
	my_data->commands = commands;
    my_data->num_commands = i;
    my_data->infile = argv[1];
    my_data->heredoc_fd = -1;
}

int	get_here_doc(t_data *my_data, char *delimiter)
{
	char	*s;

	s = NULL;
	my_data->heredoc_fd = open("tmp.txt", O_RDWR | O_CREAT, 0644);
	if (my_data->heredoc_fd == -1)
	{
        ft_printf("%s\n", strerror(errno));
        free (my_data);
        exit(-1);
    }
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

void	ft_free_and_exit(t_data *my_data)
{
	free (my_data);
	exit(1);
}
