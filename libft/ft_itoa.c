/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:49:54 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/09 21:43:59 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n);
static size_t	get_log(size_t n);
static size_t	get_size(long n);
static size_t	handle_neg(long *number, char *number_str);

char	*ft_itoa(int n)
{
	char	*number_str;
	size_t	log;
	size_t	i;
	long	number;

	number = n;
	number_str = ft_calloc((get_size(number) + 1), sizeof(char));
	if (!number_str)
		return (NULL);
	i = handle_neg(&number, number_str);
	log = get_log(number);
	while (log)
	{
		*(number_str + i) = number / log + '0';
		number %= log;
		log /= 10;
		i++;
	}
	*(number_str + i) = '\0';
	return (number_str);
}

static size_t	get_log(size_t n)
{
	size_t	log;

	log = 1;
	while (n >= (10 * log))
		log *= 10;
	return (log);
}

static size_t	get_size(long n)
{
	size_t	size;

	size = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static size_t	handle_neg(long *number, char *number_str)
{
	if (*number < 0)
	{
		*(number_str) = '-';
		*number = -(*number);
		return (1);
	}
	else
		return (0);
}
