/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:14:48 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/22 12:34:07 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_close(int fd)
{
	if (close(fd) == -1)
	{
		perror("Close failed");
		exit(1);
	}
}

void	execute_cmd1(int *pipefd, char **argv)
{
	int		fd1;

	fd1 = open(file1, O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error opening file1");
		exit(1);
	}
	if (dup2(fd1, STDIN_FILENO) == -1)
	{
		perror("Error redirecting file1 to stdin");
		exit(1);
	}
	ft_close(fd1);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("Error redirecting output cmd1 to pipe");
		exit(1);
	}

}

void	execute_cmd2()
{

}

void	validate_arguments(int argc, char **argv)
{
	if (argc != 5)
	{
		perror("Usage: ./<program name> file1 cmd1 cmd2 file2");
		exit(1);
	}
	if (access(argv[1], F_OK) == -1)
	{
		perror("Error: file1 does not exist");
		exit(1);
	}
	if (access(argv[1], R_OK) == -1)
	{
		perror("Error: file1 not readable");
		exit(1);
	}
	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
	{
		perror("Error: file2 not writable");
		exit(1);
	}
}

void	fork1(int pipefd[], pid_t pid1)
{
	if (pid1 < 0)
	{
		perror("Fork 1 failed");
		ft_close(pipefd[0]);
		ft_close(pipefd[1]);
		exit(1);
	}
	if (pid1 == 0)
	{
		ft_close(pipefd[0]);
		execute_cmd1();
		ft_close(pipefd[1]);
		exit(0);
	}
}

void	fork2(int pipefd[], pid_t pid2)
{
	if (pid2 < 0)
	{
		perror("Fork 2 failed");
		ft_close(pipefd[0]);
		ft_close(pipefd[1]);
		exit(1);
	}
	if (pid2 == 0)
	{
		ft_close(pipefd[1]);
		execute_cmd2();
		ft_close(pipefd[0]);
		exit(0);
	}
}

void	check_child_status(int status, const char *error_message)
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

int	main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	validate_arguments(argc, argv);
	if (pipe(pipefd) == -1)
	{
		perror("Pipe failed");
		exit(1);
	}
	pid1 = fork();
	fork1(pipefd, pid1);
	pid2 = fork();
	fork2(pipefd, pid2);
	ft_close(pipefd[0]);
	ft_close(pipefd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	check_child_status(status1, "Error executing cmd1");
	check_child_status(status2, "Error executing cmd2");
	return (0);
}
