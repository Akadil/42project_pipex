/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_heredoc.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:46:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/11 15:53:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCESS_HEREDOC_H
# define FT_PREPROCESS_HEREDOC_H

# include "ft_preprocess.h"
# include "libft.h"
# include "ft_data.h"
# include "ft_error.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

static void    ft_get_here_doc(t_data *my_data, char *delimiter);

#endif