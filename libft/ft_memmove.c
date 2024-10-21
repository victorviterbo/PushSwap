/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:43:44 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/13 13:24:22 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int						i;
	unsigned char			*bsrc;
	unsigned char			*bdst;

	if (!dst && !src)
		return (NULL);
	bdst = (unsigned char *)dst;
	bsrc = (unsigned char *)src;
	if (src < dst && dst < src + n)
	{
		i = n;
		while (--i + 1)
			*(bdst + i) = *(bsrc + i);
	}
	else
	{
		i = -1;
		while ((size_t)++i < n)
			*(bdst + i) = *(bsrc + i);
	}
	return (dst);
}
