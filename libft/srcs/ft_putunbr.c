/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:34:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/09 11:50:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit(int n)
{
	char	c;

	c = n + 48;
	write(1, &c, 1);
}

int	ft_putunbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += ft_putunbr(nbr / 10);
		len += ft_putunbr(nbr % 10);
	}
	else
	{
		ft_putdigit(nbr);
		len++;
	}
	return (len);
}
