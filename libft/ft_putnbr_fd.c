/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:01:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/09 19:24:00 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd);
static size_t	get_log(size_t n);

void	ft_putnbr_fd(int n, int fd)
{
	size_t	log;
	long	number;
	char	c;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	log = get_log(number);
	while (log)
	{
		c = number / log + '0';
		write(fd, &c, 1);
		number %= log;
		log /= 10;
	}
	return ;
}

static size_t	get_log(size_t n)
{
	size_t	log;

	log = 1;
	while (n >= (10 * log))
		log *= 10;
	return (log);
}
