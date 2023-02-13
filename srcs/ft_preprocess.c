/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:29:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 18:14:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocess.h"

void	ft_preprocess(int argc, char **argv, char **env, t_data *my_data)
{
	if (argc < 5 || !env || !env[0])
		ft_perror_clean_exit(my_data, "Wrong arguments");
	if (ft_strcmp(argv[1], "here_doc") == 0)
		ft_preprocess_cmd_heredoc(argc, argv, my_data);
	else
		ft_preprocess_cmd_normal(argc, argv, my_data);
	my_data->outfile = argv[argc - 1];
	ft_preprocess_get_allPaths(my_data, env);
}
