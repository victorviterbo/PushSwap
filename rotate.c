/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:58:46 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 15:27:24 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstlast(*stack_a)->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_list **stack_b)
{
	ra(stack_b);
	write(1, "rb\n", 3);
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	ra(stack_b);
	write(1, "rr\n", 3);
	return ;
}
