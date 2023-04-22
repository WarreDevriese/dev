/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:42:10 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/22 12:45:29 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

