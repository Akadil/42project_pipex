/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:03:35 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 18:15:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execution.h"

void    ft_exec_command(t_data *my_data, int index)
{
    char    *path;
    int     pid;

    pid = fork();
    if (pid < -1)
        ft_perror_clean_exit(my_data, "Fork failed");
    if (pid == 0)
    {
        if (dup2(my_data->prev_fd, STDIN_FILENO) == -1)
            ft_perror_clean_exit(my_data, "Dup2 failed for child process");
        if (dup2(my_data->pipe_fd[1], STDOUT_FILENO) == -1)
            ft_perror_clean_exit(my_data, "Dup2 failed for child process");
        ft_clean_fds(my_data);
        path = ft_find_path_exit(my_data, my_data->commands[index]);
        if (execve(path, ft_split(my_data->commands[index], ' '), NULL) == -1)
            ft_perror_clean_exit(my_data, "Execve failed");
    }
    else
        close(my_data->prev_fd);
}