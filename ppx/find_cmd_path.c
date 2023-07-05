/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:45:54 by wdevries          #+#    #+#             */
/*   Updated: 2023/07/05 16:59:38 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strjoin_path(const char *dirs, const char *cmd)
{
	char	*full_path;
	size_t	dirs_len;
	size_t	cmd_len;

	dirs_len = ft_strlen(dirs);
	cmd_len = ft_strlen(cmd);
	full_path = malloc(dirs_len + cmd_len + 2);
	if (!full_path)
		exit(ERR_MALLOC_FAILED);
	ft_memcpy(full_path, dirs, dirs_len);
	full_path[dirs_len] = '/';
	ft_memcpy(full_path + dirs_len + 1, cmd, cmd_len);
	full_path[dirs_len + cmd_len + 1] = '\0';
	return (full_path);
}

static void	exit_exec_not_found(void)
{
	static bool	first;

	first = true;
	if (first)
	{
		first = false;
		exit(ERR_EXEC1_NOT_FOUND);
	}
	else
		exit(ERR_EXEC2_NOT_FOUND);
}

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
	ft_free_array(dirs);
	if (!full_path)
		exit_exec_not_found();
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
		exit(ERR_PATH_NOT_FOUND);
	return (path_env);
}

char	*find_cmd_path(char **envp, char *cmd)
{
	static char	*path_env;
	char		*full_path;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	if (!path_env)
		path_env = find_path_env(envp);
	full_path = search_cmd_in_dirs(path_env, cmd);
	return (full_path);
}
