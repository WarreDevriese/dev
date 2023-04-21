/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:14:48 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/21 15:35:06 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

void	execute_cmd1()
{
	
}

void	execute_cmd2()
{

}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		perror("Close failed");
	exit(1);
}

int	main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;
	
	if (pipe(pipefd) == -1)
	{
		perror("Pipe failed");
		exit(1);
	}
	pid1 = fork();
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
	
	pid2= fork();
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

	ft_close(pipefd[0]);
	ft_close(pipefd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	return (0);
}
