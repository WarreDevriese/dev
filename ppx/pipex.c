/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:14:48 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/24 14:45:13 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
	{
		perror("Close failed");
		exit(1);
	}
}

static void	validate_arguments(int argc, char **argv)
{
	if (argc != 5)
	{
		perror("Usage: ./<program name> file1 cmd1 cmd2 file2");
		exit(1);
	}
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		perror("Error file1:");
		exit(1);
	}
	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
	{
		perror("Error file2:");
		exit(1);
	}
}

static void	check_child_status(int status, const char *error_message)
{
	int	exit_status;

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status != 0)
		{
			perror(error_message);
			exit(1);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	validate_arguments(argc, argv);
	if (pipe(pipefd) == -1)
	{
		perror("Error pipe:");
		exit(1);
	}
	pid1 = fork();
	child1(pipefd, pid1, argv, envp);
	pid2 = fork();
	child2(pipefd, pid2, argv, envp);
	ft_close(pipefd[0]);
	ft_close(pipefd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	check_child_status(status1, "Error executing cmd1");
	check_child_status(status2, "Error executing cmd2");
	return (0);
}
