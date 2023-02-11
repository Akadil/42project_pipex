/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_findPath_fromEnv.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:17:34 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/11 21:11:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_data.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

static char	*ft_find_path_line(char **_env);
static int		ft_add_slashes(char **_all_paths);
static void	ft_free_2array(char **trash);

/*
	Goal:	Find all potential path of the scripts

	input:	
		_env - environment variables
	output:	
		double array (char) with all potential paths
	
	Note:	str is a pointer to env[i], so it doesn't need be to freed
*/

char	**ft_get_potential_paths(char **_env)
{
	char	**all_paths;
	char	*str;

	str = ft_find_path_line(_env);
	if (str == NULL)
		return (NULL); // This null mean that ev doesn't contain any "PATH:"
	all_paths = ft_split(ft_strstr(str, "/"), ':');
	if (!all_paths)
		return (NULL); // This one means that there was malloc problem
	if (ft_add_slashes(all_paths) == -1) // This one malloc problems
	{
		ft_free_2array(all_paths);
		return (NULL);
	}
	return (all_paths);
}

static char	*ft_find_path_line(char **_env)
{
	int		i;

	i = 0;
	while (_env[i])
	{
		if (ft_strncmp("PATH=", _env[i], 5) == 0)
			return(_env[i]);
		i++;
	}
	return (NULL);
}

static int	ft_add_slashes(char **_all_paths)
{
	char	*potential_path;
	int		i;

	i = 0;
	while (_all_paths[i])
	{
		potential_path = ft_strjoin(_all_paths[i], "/");
		if (!potential_path)
			return (-1);
		free(_all_paths[i]);
		_all_paths[i] = potential_path;
		i++;
	}
	return (0);
}

static void	ft_free_2array(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free (trash[i]);
		i++;
	}
	free (trash);
}
