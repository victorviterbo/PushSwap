/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:33:13 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/03 16:01:44 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	exit_gracefully(t_list **stack_a, t_list **stack_b,
			char *str, int status);

void	exit_gracefully(t_list **stack_a, t_list **stack_b,
	char *str, int status)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	free(str);
	if (status)
		write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
