/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_findpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:52:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/14 16:23:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execution_findPath.h"

char	*ft_find_path_exit(t_data *my_data, char *full_command)
{
	char	*temp_command;
	char	*command;
	int		i;

	command = ft_extract_command_exit(my_data, full_command);
	i = 0;
	while (my_data->paths[i] && command[0] != '\0')
	{
		temp_command = ft_strjoin(my_data->paths[i++], command);
		if (!temp_command)
			ft_free_perror_exit(my_data, command);
		if (access(temp_command, X_OK) == 0)
			return (temp_command);
		free(temp_command);
		if (errno != 2)
			ft_free_perror2_exit(my_data, command, full_command);
	}
	if (full_command[0] == '\\')
		ft_merror("bash: %s: No such file or directory\n", full_command);
	else
		ft_merror("%s: command not found\n", full_command);
	return (free(command), ft_clean_exit(my_data), NULL);
}

static char	*ft_extract_command_exit(t_data *my_data, char *_arg)
{
	char	*command;
	int		size;
	int		i;

	size = 0;
	while (_arg && _arg[size] != '\0' && _arg[size] != ' ')
		size++;
	command = (char *)malloc(sizeof(char) * (size + 1));
	if (!command)
		ft_perror_clean_exit(my_data, "Malloc failed in child process");
	i = 0;
	while (i < size)
	{
		command[i] = _arg[i];
		i++;
	}
	command[i] = '\0';
	return (command);
}

static void	ft_free_perror_exit(t_data *my_data, char *_command)
{
	free(_command);
	ft_perror_clean_exit(my_data, "Malloc failed in child process");
}

static void	ft_free_perror2_exit(t_data *my_data, char *_command,
		char *full_command)
{
	ft_perror(full_command);
	free(_command);
	ft_clean_exit(my_data);
}
