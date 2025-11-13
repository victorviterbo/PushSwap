/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:03:35 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/10 16:04:03 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int						i;

	if (!dst || ! src)
		return (NULL);
	if (src < dst && dst < src + n)
	{
		i = n - 1;
		while (i + 1)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < n)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dst);
}
