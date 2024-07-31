/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:19:23 by Olly              #+#    #+#             */
/*   Updated: 2024/07/31 16:52:00 by Olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char	*join_path(const char *dir, const char *cmd)
{
	char	*temp;
	char	*full_path;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

int	is_executable(const char *path)
{
	return (access(path, F_OK | X_OK) == 0);
}

char	*get_path(const char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*env_path;
	int		i;

	i = 0;
	if ((cmd[0] == '/' || cmd[0] == '.') && (is_executable(cmd)))
		return (ft_strdup(cmd));
	env_path = get_env_path(env);
	paths = ft_split(env_path, ':');
	if (!env_path || !paths)
		return (NULL);
	while (paths[i])
	{
		path = join_path(paths[i], cmd);
		if (path && is_executable(path))
		{
			ft_free_tab(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_tab(paths);
	return (NULL);
}
