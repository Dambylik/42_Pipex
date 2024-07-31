/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:42:18 by Olly              #+#    #+#             */
/*   Updated: 2024/07/31 16:16:01 by Olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(char *cmd, char **env)
{
	char	**splited_cmd;
	char	*path;

	splited_cmd = ft_split(cmd, ' ');
	if (!splited_cmd)
	{
		perror("ft_split");
		exit(EXIT_FAILURE);
	}
	path = get_path(splited_cmd[0], env);
	if (path && execve(path, splited_cmd, env) == -1)
	{
		perror("execve");
		ft_free_tab(splited_cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(splited_cmd[0], 2);
	}
	ft_free_tab(splited_cmd);
	free(path);
	exit(EXIT_FAILURE);
}

void	handle_child(char **argv, char **env, int *pipe_fd)
{
	int	infile_fd;

	infile_fd = open_file(argv[1], O_RDONLY);
	if (dup2(infile_fd, STDIN_FILENO) == -1
		|| dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(infile_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	exec_command(argv[2], env);
}

void	handle_parent(char **argv, char **env, int *pipe_fd)
{
	int	outfile_fd;

	wait(NULL);
	outfile_fd = open_file(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1
		|| dup2(outfile_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(outfile_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	exec_command(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (argc != 5)
		exit_handler("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		handle_child(argv, env, pipe_fd);
	else
		handle_parent(argv, env, pipe_fd);
	return (0);
}
