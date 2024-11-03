/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:32:18 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/03 16:29:55 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *str);

int	ft_isnumber(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		if (!ft_strchr("0123456789+-", *(str + i)))
			return (0);
		i++;
	}
	if (ft_strlen(str) > ft_strlen(ft_itoa(INT_MIN)))
		return (0);
	else if ((ft_strlen(str) == ft_strlen(ft_itoa(INT_MAX))) && *str != '-')
		return (ft_memcmp(ft_itoa(INT_MAX), str, ft_strlen(str)) >= 0);
	else if (ft_strlen(str) == ft_strlen(ft_itoa(INT_MIN)))
		return (ft_memcmp(ft_itoa(INT_MIN), str, ft_strlen(str)) >= 0);
	return (1);
}
