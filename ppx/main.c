/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:14:48 by wdevries          #+#    #+#             */
/*   Updated: 2023/07/05 10:00:46 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_ppx(int fd)
{
	if (close(fd) == -1)
		handle_error(ERR_CLOSE_FD, NULL);
}

static void	validate_arguments(int argc, char **argv)
{
	if (argc != 5)
		ft_putstr_fd(
			"Usage: ./<program name> file1 cmd1 cmd2 file2\n", STDERR_FILENO);
	if (access(argv[1], F_OK | R_OK) == -1)
		handle_error(ERR_FILE1_ACCESS, argv);
	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
		handle_error(ERR_FILE2_WRITE, argv);
}

static void	check_child_status(int status, char **argv)
{
	int	error_code;

	if (WIFEXITED(status))
	{
		error_code = WEXITSTATUS(status);
		if (error_code != 0)
			handle_error(error_code, argv);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid[2];
	int		status[2];

	validate_arguments(argc, argv);
	if (pipe(pipefd) == -1)
		handle_error(ERR_PIPE_CREATION, NULL);
	pid[0] = fork();
	child1(pipefd, pid[0], argv, envp);
	pid[1] = fork();
	child2(pipefd, pid[1], argv, envp);
	ft_close_ppx(pipefd[0]);
	ft_close_ppx(pipefd[1]);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
	check_child_status(status[0], argv);
	check_child_status(status[1], argv);
	return (0);
}
