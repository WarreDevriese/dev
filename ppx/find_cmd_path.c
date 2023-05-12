/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:45:54 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/12 14:28:49 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_dirs(char **dirs)
{
	int	i;

	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
}

static char	*ft_strjoin_path(const char *dirs, const char *cmd)
{
	char	*full_path;
	size_t	dirs_len;
	size_t	cmd_len;

	dirs_len = ft_strlen(dirs);
	cmd_len = ft_strlen(cmd);
	full_path = malloc(dirs_len + cmd_len + 2);
	if (!full_path)
	{
		perror("Malloc failed");
		return (NULL);
	}
	ft_memcpy(full_path, dirs, dirs_len);
	full_path[dirs_len] = '/';
	ft_memcpy(full_path + dirs_len + 1, cmd, cmd_len);
	full_path[dirs_len + cmd_len + 1] = '\0';
	return (full_path);
}

#include <stdio.h>

static char	*search_cmd_in_dirs(char *path_env, char *cmd)
{
	char	*full_path;
	char	**dirs;
	int		i;

	full_path = NULL;
	dirs = ft_split(path_env, ':');
	i = 0;
	while (dirs[i])
	{
		full_path = ft_strjoin_path(dirs[i++], cmd);
		if (access(full_path, F_OK) == 0 || !full_path)
			break ;
		free(full_path);
		full_path = NULL;
	}
	ft_free_dirs(dirs);
	if (!full_path)
	{
		perror("Executable not found in PATH");
		exit(1);
	}
	printf("%s", full_path);
	return (full_path);
}

static char	*find_path_env(char **envp)
{
	char	*path_env;

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
	return (path_env);
}

char	*find_cmd_path(char **envp, char *cmd)
{
	char	*path_env;
	char	*full_path;

	path_env = find_path_env(envp);
	full_path = search_cmd_in_dirs(path_env, cmd);
	return (full_path);
}
