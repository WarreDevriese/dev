/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:49:21 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/22 17:03:08 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

void	ft_close(int fd);
char	*find_cmd_path(char **argv, char **envp);
void	child2(int pipefd[], pid_t pid2, char **argv, char **envp);
void	child1(int pipefd[], pid_t pid1, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);

#endif
