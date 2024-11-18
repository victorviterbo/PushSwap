/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:35:39 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/18 10:54:10 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	usort(t_list **stack_a, t_list **stack_b, int size);
void	usort_swap(t_list **stack_a, char ab);
void	usort1(t_list **stack_a, t_list **stack_b);
void	usort2(t_list **stack_a, t_list **stack_b);
void	usort3(t_list **stack_a, t_list **stack_b);

void	usort(t_list **stack_a, t_list **stack_b, int size)
{
	int	int1;
	int	int2;
	int	int3;

	if (size > 3)
	{
		push_bloc(stack_a, stack_b, size - 3, 1);
		usort_swap(stack_b, 'b');
	}
	if (size == 2)
	{
		usort_swap(stack_a, 'a');
		rotate_i(stack_a, NULL, 2, 'a');
		return ;
	}
	int1 = ft_parse_as((*stack_a)->content, INT);
	int2 = ft_parse_as((*stack_a)->next->content, INT);
	int3 = ft_parse_as((*stack_a)->next->next->content, INT);
	if (int1 < int2 && int1 < int3)
		usort1(stack_a, stack_b);
	else if (int2 < int1 && int2 < int3)
		usort2(stack_a, stack_b);
	else if (int3 < int1 && int3 < int2)
		usort3(stack_a, stack_b);
	return ;
}

void	usort_swap(t_list **stack, char ab)
{
	if (!stack || !*stack || ft_lstsize(*stack) < 2)
		return ;
	if ((*stack)->i > (*stack)->next->i && ab == 'a')
		sa(stack);
	else if ((*stack)->i < (*stack)->next->i && ab == 'b')
		sb(stack);
	return ;
}

void	usort1(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	usort_swap(stack_a, 'a');
	rra(stack_a);
	merge(stack_a, stack_b, 3);
	return ;
}

void	usort2(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	ra(stack_a);
	usort_swap(stack_a, 'a');
	rra(stack_a);
	merge(stack_a, stack_b, 3);
	return ;
}

void	usort3(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	sa(stack_a);
	ra(stack_a);
	pa(stack_a, stack_b);
	usort_swap(stack_a, 'a');
	rra(stack_a);
	merge(stack_a, stack_b, 3);
	return ;
}
