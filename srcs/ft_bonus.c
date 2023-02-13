/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:15:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 18:34:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

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
		ft_prepare_fd(argc, argv, my_data, i);
		if (my_data->prev_fd != -1)
			ft_exec_command(my_data, i);
		i++;
	}
	ft_wait_children(my_data);
	ft_close_heredoc(my_data);
	ft_clean_full(my_data);
	return (0);
}
