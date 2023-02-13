/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution_findPath.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:41:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 17:11:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTION_FINDPATH_H
# define FT_EXECUTION_FINDPATH_H

# include "libft.h"
# include "ft_data.h"
# include "ft_error.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

static char	*ft_extract_command_exit(t_data *my_data, char *_arg);
static void	ft_free_perror_exit(t_data *my_data, char *_command);
static void	ft_free_perror2_exit(t_data *my_data, char *_command);

#endif