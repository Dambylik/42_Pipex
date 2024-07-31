/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:06:09 by Olly              #+#    #+#             */
/*   Updated: 2024/07/31 16:36:50 by Olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h> // open
# include <stdio.h> // perror
# include <stdlib.h> // exit, malloc, free
# include <sys/wait.h> // waitpid
# include <unistd.h> // pipe, fork, close, execve, access

void	exit_handler(const char *message);
void	ft_free_tab(char **tab);
int		open_file(const char *file, int flags);
char	*get_env_path(char **env);
char	*join_path(const char *dir, const char *cmd);
char	*get_path(const char *cmd, char **env);
void	exec_command(char *cmd, char **env);

#endif 
