/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:45:54 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/22 13:04:51 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*find_cmd_path(char **argv, char **envp)
{
	char	*path_env;
	char	*full_path;
	char	**dirs;
	char	*buffer;

	path_env = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path_env = *envp + 5;
			break ;
		}
		envp++
	}
	if (!path_env)
	{
		perror("PATH environment variable not found");
		exit(1);
	}
	
	return (full_path);	
}
