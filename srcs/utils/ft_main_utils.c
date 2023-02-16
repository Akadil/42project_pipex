/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:15:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/16 15:57:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_error.h"
#include "libft.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_wait_for_child_processes(t_data *my_data)
{
	int	i;
	int	status;

	i = 0;
	while (i < my_data->active_cmds)
	{
		if (wait(&status) == -1)
			ft_perror_clean_exit(my_data, "Wait Failed");
		if (WIFSIGNALED(status) && WTERMSIG(status) != 13)
			ft_printf_stderr("Child was terminated by signal %d\n",
								WTERMSIG(status));
		i++;
	}
}

/*
		Check if I can execute the command

		If file couldn't be open, then prepare_pipes will set
		my_data->prev_fd to -1
*/
int	ft_check_condition_to_execute(t_data *my_data)
{
	if (my_data->prev_fd != -1)
		return (1);
	return (0);
}
