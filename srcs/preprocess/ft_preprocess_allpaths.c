/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_allpaths.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:20:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/16 15:53:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocess_allPaths.h"

/*
		Save all possible paths of commands from environment variables
*/
void	ft_preprocess_get_allpaths(t_data *my_data, char **_env)
{
	char	**all_paths;
	char	*path_variable;

	path_variable = ft_find_path_variable(_env);
	if (path_variable == NULL)
		ft_merror_clean_exit(my_data, "%s\n", "No \"PATH=\" in environment variables");
	all_paths = ft_split(ft_strstr(path_variable, "/"), ':'); // ft_strstr() removes "PATH=/"
	if (!all_paths)
		ft_perror_clean_exit(my_data, "Malloc failed");
	if (ft_add_slashes(all_paths) == -1) // Refactoring paths
	{
		ft_free_double_array(all_paths);
		ft_perror_clean_exit(my_data, "Malloc failed");
	}
	my_data->paths = all_paths;
}

static char	*ft_find_path_variable(char **_env)
{
	int	i;

	i = 0;
	while (_env[i])
	{
		if (ft_strncmp("PATH=", _env[i], 5) == 0)
			return (_env[i]);
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

static void	ft_free_double_array(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
}
