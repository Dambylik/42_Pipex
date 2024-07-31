/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:43:46 by Olly              #+#    #+#             */
/*   Updated: 2024/07/31 16:19:10 by Olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_handler(const char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	open_file(const char *file, int flags)
{
	int	fd;

	fd = open(file, flags, 0777);
	if (fd < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
