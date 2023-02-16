/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:13:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 21:06:46 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "ft_clean.h"
# include "ft_data.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	ft_error(void);
void	ft_perror(char *str);
void	ft_merror(char *str, char *param);
void	ft_error_clean_exit(t_data *my_data);
void	ft_perror_clean_exit(t_data *my_data, char *str);
void	ft_merror_clean_exit(t_data *my_data, char *str, char *param);
void	ft_clean_exit(t_data *my_data);
void	ft_error_exit(void);

#endif