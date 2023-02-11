/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:03:35 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/11 21:37:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execution.h"

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
    char    *path;
    int     pid;

    pid = fork();
    if (pid < -1)
        ft_perror_clean_full_exit(my_data, "Fork failed");
    if (pid == 0)
    {
        if (dup2(my_data->prev_fd, STDIN_FILENO))
            ft_perror_clean_full_exit(my_data, "Dup2 failed");
        if (dup2(my_data->pipe_fd[1], STDOUT_FILENO))
            ft_perror_clean_full_exit(my_data, "Dup2 failed");
        ft_clean_fds(my_data);
        path = ft_find_path(my_data->commands[index], my_data->paths);
        if (!path)
            ft_strange_case(my_data, index);
        if (execve(path, ft_split(my_data->commands[index], ' '), NULL) == -1)
            ft_perror_clean_full_exit(my_data, "Execve failed");
    }
    else
        close(my_data->prev_fd);
}