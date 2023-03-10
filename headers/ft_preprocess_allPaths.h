/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_allPaths.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:31:31 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/16 15:17:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCESS_ALLPATHS_H
# define FT_PREPROCESS_ALLPATHS_H

# include "ft_data.h"
# include "ft_error.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

static char	*ft_find_path_variable(char **_env);
static int	ft_add_slashes(char **_all_paths);
static void	ft_free_double_array(char **trash);

#endif