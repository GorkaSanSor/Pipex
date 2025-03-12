/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:07:47 by gsantill          #+#    #+#             */
/*   Updated: 2025/03/12 17:22:20 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_redirections(int i, int n_cmds, int fd_in, int fd_out, int **pipes)
{
	if (i == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		if (n_cmds > 1)
			dup2(pipes[i][1], STDOUT_FILENO);
	}
	else if (i == n_cmds - 1)
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
	}
	else
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		dup2(pipes[i][1], STDOUT_FILENO);
	}
}

void	ft_close_pipes_in_child(int n_cmds, int **pipes)
{
	int	j;

	j = 0;
	while (j < n_cmds - 1)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
}

void	ft_fork_and_execute(int i, int n_cmds, int fd_in, int fd_out,
			int **pipes, char **argv, char **envp, int here_doc)
{
	pid_t	pid;
	int		cmd_index;
	char	**cmd_args;
	char	*cmd_path;

	pid = fork();
	if (pid == -1)
		ft_error_exit(FORK_ERR, 1);
	if (pid == 0)
	{
		ft_redirections(i, n_cmds, fd_in, fd_out, pipes);
		ft_close_pipes_in_child(n_cmds, pipes);
		if (here_doc)
			cmd_index = i + 3;
		else
			cmd_index = i + 2;
		cmd_args = ft_split(argv[cmd_index], ' ');
		cmd_path = ft_get_exec_cmd(cmd_args[0], ft_get_path(envp));
		if (execve(cmd_path, cmd_args, envp) == -1)
		{
			ft_free_array(cmd_args);
			ft_free_str(cmd_path);
			ft_error_exit(CMD_ERR, 1);
		}
	}
}

int main(int argc, char **argv, char **envp)
{
	int here_doc_mode;
	int fd_in;
	int fd_out;
	int n_cmds;
	int **pipes;
	int i;

	here_doc_mode = 0;
	if (ft_strcmp(argv[1], "here_doc_mode") == 0)
		here_doc_mode = 1;
	
	ft_check_errors(argc, argv, &fd_in, &fd_out, pipefd);

	close(fd_in);
	close(fd_out);
	return (0);
}