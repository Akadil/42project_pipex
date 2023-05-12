/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:38:48 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/12 16:16:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H

typedef struct s_data
{
	char	*infile;
	char	*outfile;

	char	**paths;

	int		prev_fd;
	int		pipe_fd[2];

	int		num_commands;
	int		active_cmds;

	char	**commands;

	int		heredoc_fd;
}			t_data;

#endif