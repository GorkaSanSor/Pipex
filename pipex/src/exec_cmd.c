/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:25:39 by gsantill          #+#    #+#             */
/*   Updated: 2025/03/12 17:12:30 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// pipefd[0] → read
// pipefd[1] → write

// Finds the full executable path of a command by searching in system paths.
char	*ft_get_exec_cmd(char *cmd, char **paths)
{
	char    *path;
	char    *tmp;
	
	if (cmd[0] == '/' || ft_strncmp(cmd, "./", 2) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		ft_error_exit(CMD_ERR, 1);
	}
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		paths++;
	}
	ft_error_exit(CMD_ERR, 1);
	return (NULL);
}

