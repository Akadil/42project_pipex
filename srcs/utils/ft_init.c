/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:55:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/16 15:56:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_error.h"

/*
		Initialize my data and set it to "zero"
*/
void	ft_init_my_data(t_data **my_data)
{
	t_data	*_my_data;

	_my_data = (t_data *)malloc(sizeof(t_data));
	if (!_my_data)
		ft_error_exit();
	_my_data->infile = NULL;
	_my_data->outfile = NULL;
	_my_data->paths = NULL;
	_my_data->pipe_fd[0] = -1;
	_my_data->pipe_fd[1] = -1;
	_my_data->prev_fd = -1;
	_my_data->num_commands = -1;
	_my_data->active_cmds = 0;
	_my_data->commands = NULL;
	_my_data->heredoc_fd = -1;
	*my_data = _my_data;
}
