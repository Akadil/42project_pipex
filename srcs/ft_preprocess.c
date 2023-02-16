/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:29:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/16 14:18:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocess_b.h"

void	ft_preprocess(int argc, char **argv, char **env, t_data *my_data)
{
	if (argc < 5 || !env || !env[0])
		ft_merror_clean_exit(my_data, "%s\n", "Wrong arguments");
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			ft_merror_clean_exit(my_data, "%s\n", "Wrong arguments");
		ft_preprocess_cmd_heredoc(argc, argv, my_data);
	}
	else
		ft_preprocess_cmd_normal(argc, argv, my_data);
	my_data->outfile = argv[argc - 1];
	ft_preprocess_get_allpaths(my_data, env);
}
