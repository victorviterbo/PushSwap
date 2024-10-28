/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:50:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 19:57:27 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		get_min(t_list **stack_a);
int		get_max(t_list **stack_a);
void	reset_a(t_list **stack_a);
void	reset_b(t_list **stack_b);

int	get_min(t_list **stack_a)
{
	int		min;
	t_list	*current;

	min = INT_MAX;
	current = *stack_a;
	while (current)
	{
		if (*(int *)current->content < min)
			min = *(int *)current->content;
		current = current->next;
	}
	return (min);
}

int	get_max(t_list **stack_a)
{
	int		max;
	t_list	*current;

	max = INT_MIN;
	current = *stack_a;
	while (current)
	{
		if (*(int *)current->content > max)
			max = *(int *)current->content;
		current = current->next;
	}
	return (max);
}

void	reset_a(t_list **stack_a)
{
	while (*(int *)(*stack_a)->content != get_min(stack_a))
		ra(stack_a);
	return ;
}

void	reset_b(t_list **stack_b)
{
	while (*(int *)(*stack_b)->content != get_max(stack_b))
		rb(stack_b);
	return ;
}
