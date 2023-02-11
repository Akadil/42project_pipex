/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:57:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/11 15:52:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCESS_H
# define FT_PREPROCESS_H

# include "ft_data.h"
# include "ft_error.h"
# include "libft.h"

void    ft_preprocess_cmd_heredoc(int argc, char **argv, t_data *my_data);
void    ft_preprocess_cmd_normal(int argc, char **argv, t_data *my_data);

#endif