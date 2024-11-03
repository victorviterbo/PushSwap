/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:06:37 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/03 15:38:35 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		number;

	i = 0;
	sign = 1;
	number = 0;
	while ((9 <= *(str + i) && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	if (*(str + i) == '-')
	{
		sign *= -1;
		i++;
	}
	else if (*(str + i) == '+')
		i++;
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		number = number * 10 + *(str + i) - '0';
		i++;
	}
	return (sign * number);
}
