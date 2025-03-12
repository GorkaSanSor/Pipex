/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:24:46 by gsantill          #+#    #+#             */
/*   Updated: 2025/03/12 17:15:17 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* --------------------------C STANDARD LIBRARIES-----------------------------*/

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

/* -------------------------------ERROR CODES-------------------------------- */

# define WRONG_ARGS "Pipex error: use → ./pipex file1 cmd1 cmd2 file2\n"
# define PIPE_ERR "Pipex error: fail creating pipe\n"
# define FORK_ERR "Pipex error: fail in fork()\n"
# define FILE_ERR "Pipex error: file problem\n"
# define CMD_ERR "Pipex error: command not found\n"
# define MALLOC_ERR "Pipex error: malloc problem\n"

/* ------------------------------ MAIN FUNCTIONS ---------------------------- */

void	ft_check_errors(int argc, char **argv, 
			int *fd_in, int *fd_out, int pipefd[2]);
void	ft_error_exit(char *err_type, int exit_code);
void	ft_check_access(const char *pathname);
char	**ft_get_path(char **env);
char	*ft_get_exec_cmd(char *cmd, char **paths);
int		**create_pipes(int n_pipes);
void	close_all_pipes(int **pipes, int n_pipes);
void	ft_redirections(int i, int n_cmds, int fd_in, int fd_out, int **pipes);
void	ft_close_pipes_in_child(int n_cmds, int **pipes);
void	ft_fork_and_execute(int i, int n_cmds, int fd_in, int fd_out,
			int **pipes, char **argv, char **envp, int here_doc);
void	ft_free_array(char **arr);
void	ft_free_str(char *str);

#endif