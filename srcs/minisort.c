/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:34:01 by vviterbo          #+#    #+#             */
/*   Updated: 2025/09/02 11:38:42 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	minisort(t_list **stack_a, t_list **stack_b);
void	usort_swap(t_list **stack_a, char ab);
void	msort3(t_list **stack_a);
void	msort4(t_list **stack_a, t_list **stack_b);
void	msort5(t_list **stack_a, t_list **stack_b);

void	minisort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		usort_swap(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		msort3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		msort4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		msort5(stack_a, stack_b);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	exit_gracefully(NULL, NULL, EXIT_FAILURE);
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

void	msort3(t_list **stack_a)
{
	if (get_n(stack_a, 0) < get_n(stack_a, 1)
		&& get_n(stack_a, 0) < get_n(stack_a, 2)
		&& get_n(stack_a, 1) > get_n(stack_a, 2))
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (get_n(stack_a, 1) < get_n(stack_a, 0)
		&& get_n(stack_a, 1) < get_n(stack_a, 2))
	{
		if (get_n(stack_a, 0) < get_n(stack_a, 2))
			sa(stack_a);
		else
			ra(stack_a);
	}
	else if (get_n(stack_a, 2) < get_n(stack_a, 0)
		&& get_n(stack_a, 2) < get_n(stack_a, 1))
	{
		usort_swap(stack_a, 'a');
		rra(stack_a);
	}
	return ;
}

void	msort4(t_list **stack_a, t_list **stack_b)
{
	if (get_n(stack_a, 1) == ft_lstmini(stack_a))
		sa(stack_a);
	else if (get_n(stack_a, 2) == ft_lstmini(stack_a))
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (get_n(stack_a, 3) == ft_lstmini(stack_a))
		rra(stack_a);
	pb(stack_a, stack_b);
	msort3(stack_a);
	pa(stack_a, stack_b);
	return ;
}

void	msort5(t_list **stack_a, t_list **stack_b)
{
	if (get_n(stack_a, 1) == ft_lstmini(stack_a))
		sa(stack_a);
	else if (get_n(stack_a, 2) == ft_lstmini(stack_a))
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (get_n(stack_a, 3) == ft_lstmini(stack_a))
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (get_n(stack_a, 4) == ft_lstmini(stack_a))
		rra(stack_a);
	pb(stack_a, stack_b);
	msort4(stack_a, stack_b);
	pa(stack_a, stack_b);
	return ;
}
