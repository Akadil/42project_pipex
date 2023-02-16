/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:15:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/14 19:03:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_error_clean_exit(t_data *my_data)
{
	ft_error();
	ft_clean_full(my_data);
	exit(-1);
}

void	ft_perror_clean_exit(t_data *my_data, char *str)
{
	ft_perror(str);
	ft_clean_full(my_data);
	exit(-1);
}

void	ft_merror_clean_exit(t_data *my_data, char *str, char *param)
{
	ft_merror(str, param);
	ft_clean_full(my_data);
	exit(-1);
}

void	ft_clean_exit(t_data *my_data)
{
	ft_clean_full(my_data);
	exit(-1);
}

void	ft_error_exit(void)
{
	ft_error();
	exit(-1);
}
