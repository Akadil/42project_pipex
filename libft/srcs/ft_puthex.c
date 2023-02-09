/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:04:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/09 11:50:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_transformer(unsigned int nbr, char *base, int *len)
{
	if (nbr > 15)
	{
		ft_transformer(nbr / 16, base, len);
		ft_transformer(nbr % 16, base, len);
	}
	else
	{
		*len = *len + 1;
		ft_putchar_fd(base[nbr % 16], 1);
	}
}

int	ft_puthex(unsigned int nbr, char c)
{
	int	len;

	len = 0;
	if (c == 'x')
		ft_transformer(nbr, "0123456789abcdef", &len);
	else
		ft_transformer(nbr, "0123456789ABCDEF", &len);
	return (len);
}
