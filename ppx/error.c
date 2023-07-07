/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:36:25 by wdevries          #+#    #+#             */
/*   Updated: 2023/07/07 08:56:02 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_error_messages(char **em, char **argv)
{
	em[ERR_NONE] = "Unknown error";
	em[ERR_CLOSE_FD] = "close";
	em[ERR_FILE2_WRITE] = argv[4];
	em[ERR_FILE1_ACCESS] = argv[1];
	em[ERR_PIPE_CREATION] = "pipe";
	em[ERR_CMD1_EXECUTION] = argv[2];
	em[ERR_CMD2_EXECUTION] = argv[3];
	em[ERR_OPEN_FILE1] = argv[1];
	em[ERR_DUP_FILE1_STDIN] = "dup2";
	em[ERR_DUP_CMD1_PIPE] = "dup2";
	em[ERR_FORK1_FAILED] = "fork";
	em[ERR_OPEN_FILE2] = argv[4];
	em[ERR_DUP_PIPE_STDIN_CMD2] = "dup2";
	em[ERR_DUP_STDOUT_CMD2_FILE2] = "dup2";
	em[ERR_FORK2_FAILED] = "fork";
	em[ERR_MALLOC_FAILED] = "malloc";
	em[ERR_EXEC1_NOT_FOUND] = argv[2];
	em[ERR_EXEC2_NOT_FOUND] = argv[3];
	em[ERR_PATH_NOT_FOUND] = "PATH environment variable not found";
}

void	handle_error(t_error_code err, char **argv)
{
	char	*em[ERR_TOTAL];

	init_error_messages(em, argv);
	if (errno)
		perror(em[err]);
	else
		ft_putstr_fd(em[err], 2);
	exit(err);
}
