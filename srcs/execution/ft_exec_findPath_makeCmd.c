/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_findPath_makeCmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:52:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/11 21:52:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_get_size_of_word(char *str);
static char	*ft_extract_command(char *_arg);

char	*ft_find_path(t_data *my_data, char *arg, char **all_paths)
{
	char	*temp_command;
	char	*command;
	int		i;

	command = ft_extract_command(arg);
	if (!command)
		return (NULL); // malloc fail
	i = 0;
	while (all_paths[i])
	{
		temp_command = ft_strjoin(all_paths[i], command);
		if (!temp_command)
			return (free(command), NULL); // malloc fail
		if (access(temp_command, X_OK) == 0)
			return(temp_command);
		free(temp_command);
		i++;
	}
	return (free(command), NULL); // Couldn't find the command
}

static char	*ft_extract_command(char *_arg)
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

static int	ft_get_size_of_word(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (size);
	while (str[size] && str[size] != ' ')
		size++;
	return (size);
}
