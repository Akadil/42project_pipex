/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:01:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 16:18:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

// I have to change the ft_printf. Because It is printing to stdout
void    ft_error()
{
    ft_printf("%s\n", strerror(errno));
}

void    ft_perror(char *str)
{
    perror(str);
}

void    ft_merror(char *str, char *param)
{
    ft_printf(str, param);
}

void    ft_error_clean_exit(t_data *my_data)
{
    ft_error();
    ft_clean_full(my_data);
    exit(-1);
}

void    ft_perror_clean_exit(t_data *my_data, char *str)
{
    ft_perror(str);
    ft_clean_full(my_data);
    exit(-1);
}

void    ft_merror_clean_exit(t_data *my_data, char *str, char *param)
{
    ft_merror(str, param);
    ft_clean_full(my_data);
    exit(-1);
}

void    ft_clean_exit(t_data *my_data)
{
    ft_clean_full(my_data);
    exit(-1);
}

void    ft_error_exit()
{
    ft_error();
    exit(-1);
}
