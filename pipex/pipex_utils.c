/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:45:54 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/22 13:58:27 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_arr(char **dirs)
{
	int		i;

	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
}

char    *ft_strjoin_path(const char *s1, const char *s2)
{
    char    *result;
    size_t  s1_len;
    size_t  s2_len;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    result = malloc(s1_len + s2_len + 2);
    if (!result)
		return (NULL);
    ft_memcpy(result, s1, s1_len);
    result[s1_len] = '/';
    ft_memcpy(result + s1_len + 1, s2, s2_len);
    result[s1_len + s2_len + 1] = '\0';
    return (result);
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
		full_path = ft_strjoin_path(*dirs, cmd);
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
