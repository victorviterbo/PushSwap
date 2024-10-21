/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:21:23 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/13 13:24:16 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*bdst;
	unsigned char	*bsrc;

	if (!dst && !src)
		return (NULL);
	i = 0;
	bdst = (unsigned char *)dst;
	bsrc = (unsigned char *)src;
	while (i < n)
	{
		*(bdst + i) = *(bsrc + i);
		i++;
	}
	return (dst);
}
