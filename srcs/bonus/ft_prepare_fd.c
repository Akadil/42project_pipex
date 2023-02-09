/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:15:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/09 19:21:08 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "libft.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

static void    ft_prepare_beg(t_data *my_data);
static void    ft_prepare_mid(t_data *my_data);
static void    ft_prepare_end(int argc, char **argv, t_data *my_data);

void    ft_prepare_fds(int argc, char **argv, t_data *my_data, int index)
{
	int	last_ind;

	last_ind = my_data->num_commands - 1;
    if (index == 0)
        ft_prepare_beg(my_data);
    else if (index != last_ind)
        ft_prepare_mid(my_data);
    else
        ft_prepare_end(argc, argv, my_data);
}

void    ft_prepare_beg(t_data *my_data)
{
    int fd[2];

    fd[0] = -1;
    fd[1] = -1;
    if (pipe(fd) == -1)
        ft_printf("%s\n", strerror(errno));
    my_data->pipe_fd[0] = fd[0];
    my_data->pipe_fd[1] = fd[1];
    my_data->prev_fd = open(my_data->infile, O_RDONLY);
    if (my_data->prev_fd == -1)
        ft_printf("%s\n", strerror(errno));
}

void    ft_prepare_mid(t_data *my_data)
{
    int	fd[2];

    fd[0] = -1;
    fd[1] = -1;
    my_data->prev_fd = my_data->pipe_fd[0];
    close(my_data->pipe_fd[1]);
	if (pipe(fd) == -1)
        ft_printf("%s\n", strerror(errno));
	my_data->pipe_fd[1] = fd[1];
	my_data->pipe_fd[0] = fd[0];
}

void    ft_prepare_end(int argc, char **argv, t_data *my_data)
{
	int	fd_out;
	int	last_ind;

	last_ind = argc - 1;
	close(my_data->pipe_fd[1]);
	my_data->prev_fd = my_data->pipe_fd[0];
    my_data->pipe_fd[0] = -1;
	fd_out = open(argv[last_ind], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd_out == -1)
        ft_printf("%s\n", strerror(errno));
    my_data->pipe_fd[1] = fd_out;		
}
