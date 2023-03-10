/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:28:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/16 15:55:19 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_error.h"

/*
		Close all file descriptors if open
*/
void	ft_clean_fds(t_data *my_data)
{
	if (my_data->prev_fd != -1)
		close(my_data->prev_fd);
	if (my_data->pipe_fd[0] != -1)
		close(my_data->pipe_fd[0]);
	if (my_data->pipe_fd[1] != -1)
		close(my_data->pipe_fd[1]);
}

/*
		Free my data
*/
void	ft_clean_data(t_data *my_data)
{
	int	i;

	if (my_data)
	{
		if (my_data->commands)
			free(my_data->commands);
		if (my_data->paths)
		{
			i = 0;
			while (my_data->paths[i])
			{
				free(my_data->paths[i]);
				i++;
			}
			free(my_data->paths);
		}
		free(my_data);
	}
}

/*
		Delete temporary created file for here_doc
*/
void	ft_clean_heredoc(t_data *my_data)
{
	if (my_data->heredoc_fd != -1)
		unlink("srcs/tmp/tmp.txt");
}

void	ft_clean_full(t_data *my_data)
{
	ft_clean_fds(my_data);
	ft_clean_heredoc(my_data);
	ft_clean_data(my_data);
}
