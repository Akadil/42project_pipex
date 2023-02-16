/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_b.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:20:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/14 19:27:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCESS_B_H
# define FT_PREPROCESS_B_H

# include "ft_data.h"
# include "ft_error.h"
# include "libft.h"

void	ft_preprocess_cmd_heredoc(int argc, char **argv, t_data *my_data);
void	ft_preprocess_cmd_normal(int argc, char **argv, t_data *my_data);
void	ft_preprocess_get_allpaths(t_data *my_data, char **_env);

#endif