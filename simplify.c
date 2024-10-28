/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:01:34 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 21:39:34 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

char	*simplify(char *s, int last_size);
char	*cut(char *s, size_t start, size_t end, int ip);
int		gotonext(char *s, int i);

char	*simplify(char *s, int last_size)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (last_size == ft_strlen(s))
		return (s);
	last_size = ft_strlen(s);
	while (*(s + i))
	{
		n = gotonext(s, i);
		if ((*(s + i) == 'p' && *(s + n) == 'p')
			&& (*(s + i + 1) != *(s + n + 1)))
			return (simplify(cut(s, i, gotonext(s, n), 3), last_size));
		if ((*(s + i) == 's' && *(s + n) == 's')
			&& (*(s + i + 1) == *(s + n + 1)))
			return (simplify(cut(s, i, gotonext(s, n), 3), last_size));
		if ((*(s + i) == 'r' && *(s + n) == 'r')
			&& ((*(s + i + 1) == 'r' && *(s + n + 1) != 'r')
				|| (*(s + i + 1) != 'r' && *(s + n + 1) == 'r'))
			&& (*(s + n - 1) == *(s + gotonext(s, n) - 1)))
			return (simplify(cut(s, i, gotonext(s, n), 3), last_size));
		i = n;
	}
}

char	*cut(char *s, size_t start, size_t end, int ip)
{
	char	*first_half;
	char	*second_half;

	first_half = ft_substr(s, 0, start);
	second_half = ft_substr(s, end, ft_strlen(s + end));
	return (ft_strjoin_ip(first_half, second_half, ip));
}

int		gotonext(char *s, int i)
{
	while (*(s + i) != '\n')
		i++;
	return (i + 1);
}