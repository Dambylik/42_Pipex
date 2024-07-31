/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:11:48 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/29 11:23:36 by Olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] != '\0'
		&& (unsigned char)s1[i] == (unsigned char)s2[i] && i < n - 1)
	{
		i++;
	}
	if ((unsigned char)s1[i] == (unsigned char)s2[i])
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
