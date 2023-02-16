/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_cmd_normal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:41:00 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 21:10:02 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_error.h"
#include <stdlib.h>

void	ft_preprocess_cmd_normal(int argc, char **argv, t_data *my_data)
{
	char	**commands;
	int		i;

	commands = (char **)malloc(sizeof(char *) * (argc - 3 + 1));
	if (!commands)
		ft_error_clean_exit(my_data);
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
