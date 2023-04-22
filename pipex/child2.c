/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:42:06 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/22 15:00:15 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	execute_cmd2()
{

}

void	child2(int pipefd[], pid_t pid2)
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

