/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:15:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/11 15:50:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include <sys/wait.h>
#include <stdio.h>

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