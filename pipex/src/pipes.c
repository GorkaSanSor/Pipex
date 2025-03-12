/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:01:11 by gsantill          #+#    #+#             */
/*   Updated: 2025/03/12 16:18:01 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	**create_pipes(int n_pipes)
{
	int **pipes;
	int  i;

	pipes = malloc(n_pipes * sizeof(int *));
	if (!pipes)
		ft_error_exit(MALLOC_ERR, 1);
	i = 0;
	while (i < n_pipes)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes)
			ft_error_exit(MALLOC_ERR, 1);
		if (pipe(pipes[i]) == -1)
			ft_error_exit(PIPE_ERR, 1);
		i++;
	}
	return (pipes);
}

void	close_all_pipes(int **pipes, int n_pipes)
{
	int  i;

	i = 0;
	while (i < n_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}