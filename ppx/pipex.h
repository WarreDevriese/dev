/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:49:21 by wdevries          #+#    #+#             */
/*   Updated: 2023/07/04 16:04:31 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef enum e_error_code
{
	ERR_NONE,
	ERR_CLOSE_FD,
	ERR_FILE1_ACCESS,
	ERR_FILE2_WRITE,
	ERR_PIPE_CREATION,
	ERR_CMD1_EXECUTION,
	ERR_CMD2_EXECUTION,
	ERR_OPEN_FILE1,
	ERR_DUP_FILE1_STDIN,
	ERR_DUP_CMD1_PIPE,
	ERR_FORK1_FAILED,
	ERR_OPEN_FILE2,
	ERR_DUP_PIPE_STDIN_CMD2,
	ERR_DUP_STDOUT_CMD2_FILE2,
	ERR_FORK2_FAILED,
	ERR_MALLOC_FAILED,
	ERR_EXEC1_NOT_FOUND,
	ERR_EXEC2_NOT_FOUND,
	ERR_PATH_NOT_FOUND,
	ERR_TOTAL
}		t_error_code;

void	ft_close_ppx(int fd);
char	*find_cmd_path(char **envp, char *cmd);
void	child2(int pipefd[], pid_t pid2, char **argv, char **envp);
void	child1(int pipefd[], pid_t pid1, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);
void	handle_error(t_error_code err, char **argv);

#endif
