/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:33:13 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/04 15:18:46 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	exit_gracefully(t_list **stack_a, t_list **stack_b,
			char *str, int status);

void	exit_gracefully(t_list **stack_a, t_list **stack_b,
			char *str, int status)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	if (str)
		free(str);
	if (status == EXIT_FAILURE)
		write(1, "Error\n", 6);
	exit(status);
}
