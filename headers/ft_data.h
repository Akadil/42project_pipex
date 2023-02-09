/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:38:48 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/09 14:04:19 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	char	**env;
	int		prev_fd;
	int		pipe_fd[2];
	int		num_commands;
	char	**commands;
	int		heredoc_fd;
}			t_data;

#endif