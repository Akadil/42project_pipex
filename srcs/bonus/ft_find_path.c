/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:17:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/09 21:56:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "libft.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static char	*ft_free(char *trash);
int	ft_get_size_of_word(char *str);
char	*ft_extract_command(char *_arg);
static char	*ft_construct_command(char *arg, char **all_paths);
char	**ft_get_potential_paths(char **_env);

char    *ft_find_path(char *str, t_data *my_data)
{
    char    **all_potential_paths;
    char    *path;

    all_potential_paths = ft_get_potential_paths(my_data->env);
    if (!all_potential_paths)
        return (0);
    path = ft_construct_command(str, all_potential_paths);

	return (path);
}


int	ft_get_size_of_word(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (size);
	while (str[size] && str[size] != ' ')
		size++;
	return (size);
}

char	*ft_extract_command(char *_arg)
{
	char	*command;
	int		size;
	int		i;

	size = ft_get_size_of_word(_arg);
	command = (char *)malloc(sizeof(char) * (size + 1));
	if (!command)
		return (NULL);
	i = 0;
	while (i < size)
	{
		command[i] = _arg[i];
		i++;
	}
	command[i] = '\0';
	return (command);
}

static char	*ft_construct_command(char *arg, char **all_paths)
{
	char	*temp_command;
	char	*command;
	int		i;

	command = ft_extract_command(arg);
	if (!command)
		return (NULL);
	i = 0;
	while (all_paths[i])
	{
		temp_command = ft_strjoin(all_paths[i], command);
		if (!temp_command)
			return (ft_free(command));
		if (access(temp_command, X_OK) == 0)
			return(temp_command);
		free(temp_command);
		i++;
	}
	return (ft_free(command));
}

static char	*ft_free(char *trash)
{
	free(trash);
	return (NULL);
}