/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:15:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/08 12:49:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_clean(t_data *my_data)
{
    printf("Do me, please!!!\n");
}

void    ft_init_my_data(t_data **my_data)
{
    t_data  *_my_data;

    _my_data = (t_data *)malloc(sizeof(t_data));
    if (!_my_data)
        exit(-1);
    *my_data = _my_data;
}

void    ft_wait_children(t_data *my_data)
{
    int i;

    i = 0;
    while (i < my_data->num_commands)
    {
        wait(NULL);
        i++;
    }
}