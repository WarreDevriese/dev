/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:42:10 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/22 16:53:12 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_execve(char **argv, char **envp)
{
	char	*cmd2;
	char	*cmd2_path;
	char	**cmd2_argv;

	cmd2 = argv[3];
	cmd2_path = find_cmd_path(argv, envp);
	cmd2_argv = ft_split(cmd2, ' ');
	if (execve(cmd2_path, cmd2_argv, envp) == -1)
	{
		perror("Error executing cmd2");
		exit(1);
	}
}

static void	execute_cmd2(int *pipefd, char **argv, char **envp)
{
	int		fd2;

	fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd2 == -1)
	{
		perror("Error opening fil21");
		exit(1);
	}
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("Error redirecting pipe to stdin cmd2");
		exit(1);
	}
	if (dup2(fd2, STDOUT_FILENO) == -1)
	{
		perror("Error redirecting stdout cmd2 to file2");
		exit(1);
	}
	ft_close(fd2);
	ft_execve(argv, envp);
}

void	child2(int pipefd[], pid_t pid2, char **argv, char **envp)
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
		execute_cmd2(pipefd, argv, envp);
		ft_close(pipefd[0]);
		exit(0);
	}
}
