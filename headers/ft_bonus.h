/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:54:07 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/09 18:27:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

#include "ft_data.h"
#include <stdio.h>

void    ft_preprocessing(int argc, char **argv, char **env, t_data *my_data);
void    ft_prepare_fds(int argc, char **argv, t_data *my_data, int index);
void    ft_exec_command(t_data *my_data, int index);
void    ft_init_my_data(t_data **my_data);
void    ft_wait_children(t_data *my_data);
void    ft_clean(t_data *my_data);

#endif