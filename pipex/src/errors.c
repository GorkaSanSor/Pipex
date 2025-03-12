/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:39:04 by gsantill          #+#    #+#             */
/*   Updated: 2025/03/12 15:24:48 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Prints an error message to stderr and exits with the given exit code.
void	ft_error_exit(char *err_type, int exit_code)
{
	ft_putstr_fd(err_type, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(exit_code);
}

// Checks arguments, opens files, creates a pipe, and handles errors.
void	ft_check_errors(int argc, char **argv, 
			int *fd_in, int *fd_out, int pipefd[2])
{
	if (argc != 5)
		ft_error_exit(WRONG_ARGS, 1);
	*fd_in = open(argv[1], O_RDONLY);
	if (*fd_in == -1)
		ft_error_exit(FILE_ERR, 1);
	*fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd_out == -1)
		ft_error_exit(FILE_ERR, 1);
	if (pipe(pipefd) == -1)
		ft_error_exit(PIPE_ERR, 1);
}
