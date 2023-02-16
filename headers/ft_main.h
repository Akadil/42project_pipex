/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:54:07 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/16 15:57:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include "ft_clean.h"
# include "ft_data.h"
# include <stdio.h>

void	ft_init_my_data(t_data **my_data);
void	ft_preprocess(int argc, char **argv, char **env, t_data *my_data);
void	ft_prepare_pipes(int argc, char **argv, t_data *my_data, int index);
int     ft_check_condition_to_execute(t_data *my_data);
void	ft_exec_command(t_data *my_data, char *command);
void	ft_wait_for_child_processes(t_data *my_data);

#endif