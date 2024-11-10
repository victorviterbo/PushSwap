/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:19:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/10 16:24:56 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

void	write_out(char *str, bool print)
{
	static char	*output = NULL;

	if (print)
	{
		output = simplify(output);
		write(1, output, ft_strlen(output));
	}
	if (!output)
	{
		output = ft_calloc(1, 1);
		if (!output)
			exit_gracefully(NULL, NULL, NULL, EXIT_FAILURE);
	}
	if (str)
		output = ft_strjoin_ip(output, str, 1);
	else
		exit_gracefully(NULL, NULL, output, EXIT_FAILURE);
	return ;
}
