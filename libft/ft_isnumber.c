/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:32:18 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/30 13:38:00 by vviterbo         ###   ########.fr       */
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
		if (!(9 <= *(str + i) && *(str + i) <= 13) && *(str + i) != 32
			&& !(ft_isdigit(*(str + i))))
			return (0);
		i++;
	}
	return (1);
}
