/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:42:10 by wdevries          #+#    #+#             */
/*   Updated: 2023/07/05 16:58:00 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_execve(char **argv, char **envp)
{
	char	*cmd1;
	char	*cmd1_path;
	char	**cmd1_argv;

	cmd1 = argv[2];
	cmd1_argv = ft_split(cmd1, ' ');
	cmd1_path = find_cmd_path(envp, cmd1_argv[0]);
	if (execve(cmd1_path, cmd1_argv, envp) == -1)
		exit(ERR_CMD1_EXECUTION);
}

static void	execute_cmd1(int *pipefd, char **argv, char **envp)
{
	int	fd1;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		exit(ERR_OPEN_FILE1);
	if (dup2(fd1, STDIN_FILENO) == -1)
		exit(ERR_DUP_FILE1_STDIN);
	ft_close_ppx(fd1);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		exit(ERR_DUP_CMD1_PIPE);
	ft_execve(argv, envp);
}

void	child1(int pipefd[], pid_t pid1, char **argv, char **envp)
{
	if (pid1 < 0)
	{
		ft_close_ppx(pipefd[0]);
		ft_close_ppx(pipefd[1]);
		exit(ERR_FORK1_FAILED);
	}
	if (pid1 == 0)
	{
		ft_close_ppx(pipefd[0]);
		execute_cmd1(pipefd, argv, envp);
		ft_close_ppx(pipefd[1]);
		exit(ERR_NONE);
	}
}
