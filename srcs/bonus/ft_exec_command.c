/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:03:35 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/09 22:07:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "libft.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_find_path(char *str, t_data *my_data);

void    ft_close_all_fds(t_data *my_data)
{
    close(my_data->prev_fd);
    close(my_data->pipe_fd[0]);
    close(my_data->pipe_fd[1]);
}

void    ft_do_something()
{
    ft_printf("I swear I will free my data after!\n");
    exit(-1);
}

void    ft_strange_case(t_data *my_data, int index)
{
    dup2(2, STDOUT_FILENO);
    if (my_data->commands[index][0] != '/')
		ft_printf("%s: command not found\n", NULL);
	else if (errno == 13)
		ft_printf("bash: %s: Permission denied\n", NULL);
	else
		ft_printf("bash: %s: No such file or directory\n", NULL);
    exit (-1);
}

void    ft_exec_command(t_data *my_data, int index)
{
    char    *str;
    int     pid;

    pid = fork();
    if (pid < 0)
        return ;
    if (pid == 0)
    {
        dup2(my_data->prev_fd, STDIN_FILENO);
        dup2(my_data->pipe_fd[1], STDOUT_FILENO);
        ft_close_all_fds(my_data);
        str = ft_find_path(my_data->commands[index], my_data);
        if (!str)
            ft_strange_case(my_data, index);
        if (execve(str, ft_split(my_data->commands[index], ' '), NULL) == -1)
            ft_do_something();
    }
    else
        close(my_data->prev_fd);
}