/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:01:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/14 19:01:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_error(void)
{
	ft_printf_stderr("%s\n", strerror(errno));
}

void	ft_perror(char *str)
{
	perror(str);
}

void	ft_merror(char *str, char *param)
{
	ft_printf_stderr(str, param);
}
