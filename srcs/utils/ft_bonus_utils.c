/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:15:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 18:50:33 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

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

void    ft_close_heredoc(t_data *my_data)
{
    if (my_data->heredoc_fd != -1)
        unlink("srcs/tmp/tmp.txt");
}
