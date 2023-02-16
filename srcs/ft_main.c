/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:15:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/16 15:20:35 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

/*
		Recreate the multiple pipes 
*/
int	main(int argc, char **argv, char **env)
{
	t_data	*my_data;
	int		i;

	my_data = NULL;
	ft_init_my_data(&my_data);
	ft_preprocess(argc, argv, env, my_data);
	i = 0;
	while (i < my_data->num_commands)
	{
		ft_prepare_pipes(argc, argv, my_data, i);
		if (ft_check_condition_to_execute(my_data) == 1)
		{
			ft_exec_command(my_data, my_data->commands[i]);
			my_data->active_cmds++;
		}
		i++;
	}
	ft_wait_for_child_processes(my_data);
	ft_clean_full(my_data);
	return (0);
}
