/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:36:25 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 16:26:26 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(t_error_code err)
{
	const char	*em[ERR_TOTAL];

	em[ERR_NONE] = "Unknown error";
	em[ERR_CLOSE_FD] = "Close failed";
	em[ERR_FILE1_ACCESS] = "Error accessing file1";
	em[ERR_FILE2_WRITE] = "Error: file2 exists but cannot be written to";
	em[ERR_PIPE_CREATION] = "Error creating pipe";
	em[ERR_CMD1_EXECUTION] = "Error executing cmd1";
	em[ERR_CMD2_EXECUTION] = "Error executing cmd2";
	em[ERR_OPEN_FILE1] = "Error opening file1";
	em[ERR_DUP_FILE1_STDIN] = "Error redirect file1 to stdin";
	em[ERR_DUP_CMD1_PIPE] = "Error redirect output cmd1 to pipe";
	em[ERR_FORK1_FAILED] = "Fork 1 failed";
	em[ERR_OPEN_FILE2] = "Error opening file2";
	em[ERR_DUP_PIPE_STDIN_CMD2] = "Error redirect pipe to stdin for cmd2";
	em[ERR_DUP_STDOUT_CMD2_FILE2] = "Error redirect stdout for cmd2 to file2";
	em[ERR_FORK2_FAILED] = "Fork 2 failed";
	em[ERR_MALLOC_FAILED] = "Memory allocation failed";
	em[ERR_EXEC_NOT_FOUND] = "Executable not found in PATH";
	em[ERR_PATH_NOT_FOUND] = "PATH environment variable not found";
	perror(em[err]);
	exit(err);
}
