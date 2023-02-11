/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_findPath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:17:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/11 21:37:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execution_find_path.h"

char    *ft_find_path(char *str, char **all_paths)
{
    char    *path;

    path = ft_construct_command(str, all_paths);
	return (path); // This one too! Also I have to free the all_potential paths!
}