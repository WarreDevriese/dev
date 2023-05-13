/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:36:25 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 11:43:21 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void handle_error(t_error_code err)
{
    const char *error_messages[ERR_TOTAL];

    error_messages[ERR_NONE] = "Unknown error";
    error_messages[ERR_CLOSE_FD] = "Close failed";
    error_messages[ERR_INVALID_ARGS] = "Usage: ./<program name> file1 cmd1 cmd2 file2";
    error_messages[ERR_FILE1_ACCESS] = "Error accessing file1";
    error_messages[ERR_FILE2_WRITE] = "Error: file2 exists but cannot be written to";
    error_messages[ERR_PIPE_CREATION] = "Error creating pipe";
    error_messages[ERR_CMD1_EXECUTION] = "Error executing cmd1";
    error_messages[ERR_CMD2_EXECUTION] = "Error executing cmd2";
    error_messages[ERR_OPEN_FILE1] = "Error opening file1";
    error_messages[ERR_REDIRECT_FILE1_STDIN] = "Error redirecting file1 to stdin";
    error_messages[ERR_REDIRECT_CMD1_PIPE] = "Error redirecting output cmd1 to pipe";
    error_messages[ERR_FORK1_FAILED] = "Fork 1 failed";
    error_messages[ERR_OPEN_FILE2] = "Error opening file2";
    error_messages[ERR_REDIRECT_PIPE_STDIN_CMD2] = "Error redirecting pipe to stdin for cmd2";
    error_messages[ERR_REDIRECT_STDOUT_CMD2_FILE2] = "Error redirecting stdout for cmd2 to file2";
    error_messages[ERR_FORK2_FAILED] = "Fork 2 failed";
    error_messages[ERR_MALLOC_FAILED] = "Memory allocation failed";
    error_messages[ERR_EXEC_NOT_FOUND] = "Executable not found in PATH";
    error_messages[ERR_PATH_NOT_FOUND] = "PATH environment variable not found";
    perror(error_messages[err]);
    exit(err);
}
