/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:42:10 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 12:31:45 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_execve(char **argv, char **envp)
{
	char	*cmd2;
	char	*cmd2_path;
	char	**cmd2_argv;

	cmd2 = argv[3];
	cmd2_argv = ft_split(cmd2, ' ');
	cmd2_path = find_cmd_path(envp, cmd2_argv[0]);
	if (execve(cmd2_path, cmd2_argv, envp) == -1)
		handle_error(ERR_CMD2_EXECUTION);
}

static void	execute_cmd2(int *pipefd, char **argv, char **envp)
{
	int	fd2;

	fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd2 == -1)
		handle_error(ERR_OPEN_FILE2);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		handle_error(ERR_REDIRECT_PIPE_STDIN_CMD2);
	if (dup2(fd2, STDOUT_FILENO) == -1)
		handle_error(ERR_REDIRECT_STDOUT_CMD2_FILE2);
	ft_close_ppx(fd2);
	ft_execve(argv, envp);
}

void	child2(int pipefd[], pid_t pid2, char **argv, char **envp)
{
	if (pid2 < 0)
	{
		ft_close_ppx(pipefd[0]);
		ft_close_ppx(pipefd[1]);
		handle_error(ERR_FORK2_FAILED);
	}
	if (pid2 == 0)
	{
		ft_close_ppx(pipefd[1]);
		execute_cmd2(pipefd, argv, envp);
		ft_close_ppx(pipefd[0]);
		exit(0);
	}
}
