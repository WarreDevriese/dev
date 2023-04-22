/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:45:54 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/22 13:54:28 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_arr(char **dirs)
{
	while (*dirs--)
		free(*dirs);
	free(dirs);
}
char	*find_cmd_path(char **argv, char **envp)
{
	char	*path_env;
	char	*full_path;
	char	*buffer_split;
	char	**dirs;
	char	*cmd;

	path_env = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path_env = *envp + 5;
			break ;
		}
		envp++;
	}
	if (!path_env)
	{
		perror("PATH environment variable not found");
		exit(1);
	}
	buffer_split = ft_strdup(path_env);
	dirs = ft_split(buffer_split, ':');
	free(buffer_split);
	cmd = argv[1];
	full_path = NULL;
	while (*dirs)
	{
		full_path = ft_strjoin(*dirs, cmd);
		if (access(full_path, F_OK) == 0)
			break ;
		free(full_path);
		full_path = NULL;
		dirs++;
	}
	ft_free_arr(dirs);
	if (!full_path)
	{
		perror("Executable not found in PATH");
		exit(1);
	}
	return (full_path);	
}
