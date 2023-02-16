/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:54:07 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/14 14:47:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include "ft_clean.h"
# include "ft_data.h"
# include <stdio.h>

void	ft_init_my_data(t_data **my_data);
void	ft_preprocess(int argc, char **argv, char **env, t_data *my_data);
void	ft_prepare_fd(int argc, char **argv, t_data *my_data, int index);
void	ft_exec_command(t_data *my_data, int index);
void	ft_close_heredoc(t_data *my_data);
void	ft_wait_children(t_data *my_data);

#endif