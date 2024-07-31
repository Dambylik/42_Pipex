/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:26:10 by julessainth       #+#    #+#             */
/*   Updated: 2024/07/29 11:13:12 by Olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c_alloc;

	if (size && SIZE_MAX / size < count)
		return (NULL);
	c_alloc = (void *)(malloc(count * size));
	if (!c_alloc)
		return (NULL);
	ft_bzero(c_alloc, count * size);
	return (c_alloc);
}
