/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:49:05 by julessainth       #+#    #+#             */
/*   Updated: 2024/07/29 11:23:56 by Olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*heap_s;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	heap_s = (char *)malloc((len + 1) * sizeof(char));
	if (!heap_s)
		return (NULL);
	i = 0;
	while (i < len && s[(size_t)(start + i)] != '\0')
	{
		heap_s[i] = s[(size_t)(start + i)];
		i++;
	}
	heap_s[i] = '\0';
	return (heap_s);
}
