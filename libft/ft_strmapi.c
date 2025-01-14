/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:15:15 by julessainth       #+#    #+#             */
/*   Updated: 2024/07/29 11:23:30 by Olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map_s;
	unsigned int	i;

	map_s = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!map_s || !s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		map_s[i] = (*f)(i, s[i]);
		i++;
	}
	map_s[i] = '\0';
	return (map_s);
}
