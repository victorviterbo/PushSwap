/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:58:46 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/23 17:18:00 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	rra(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	ft_lstlast(*stack_a)->next = *stack_a;
	(*stack_a)->next = NULL;
	(*stack_a) = tmp;
	return ;
}

void	rrb(t_list **stack_b)
{
	rra(stack_b);
	return ;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rra(stack_b);
	return ;
}
