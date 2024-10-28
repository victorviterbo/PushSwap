/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:19:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 15:27:45 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	sa(t_list **stack_a)
{
	void	*tmp;

	tmp = (((*stack_a)->next)->content);
	(((*stack_a)->next)->content) = ((*stack_a)->content);
	((*stack_a)->content) = tmp;
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_list **stack_b)
{
	sa(stack_b);
	write(1, "sb\n", 3);
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
	return ;
}