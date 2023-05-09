/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:49:21 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/01 16:43:57 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	ft_close(int fd);
char	*find_cmd_path(char **envp, char *cmd);
void	child2(int pipefd[], pid_t pid2, char **argv, char **envp);
void	child1(int pipefd[], pid_t pid1, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);

#endif