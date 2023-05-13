/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:14:48 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 14:34:55 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_ppx(int fd)
{
	if (close(fd) == -1)
		handle_error(ERR_CLOSE_FD);
}

static void	validate_arguments(int argc, char **argv)
{
	if (argc != 5)
		handle_error(ERR_INVALID_ARGS);
	if (access(argv[1], F_OK | R_OK) == -1)
		handle_error(ERR_FILE1_ACCESS);
	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
		handle_error(ERR_FILE2_WRITE);
}

static void	check_child_status(int status, t_error_code err)
{
	int	exit_status;

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status != 0)
			handle_error(err);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid[2];
	int		status[2];

	validate_arguments(argc, argv);
	if (pipe(pipefd) == -1)
		handle_error(ERR_PIPE_CREATION);
	pid[0] = fork();
	child1(pipefd, pid[0], argv, envp);
	pid[1] = fork();
	child2(pipefd, pid[1], argv, envp);
	ft_close_ppx(pipefd[0]);
	ft_close_ppx(pipefd[1]);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
	check_child_status(status[0], ERR_CMD1_EXECUTION);
	check_child_status(status[1], ERR_CMD2_EXECUTION);
	return (0);
}
