/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:45:15 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/18 17:51:57 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir);

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*next_node_a;
	t_list	*next_node_b;

	if (!stack_a || !stack_b)
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	else if (!*stack_b || ft_lstsize(*stack_b) < 1)
		return ;
	if (!*stack_a)
		next_node_a = NULL;
	else
		next_node_a = *stack_a;
	*stack_a = *stack_b;
	next_node_b = (*stack_b)->next;
	(*stack_a)->next = next_node_a;
	*stack_b = next_node_b;
	return ;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	add_instr("pa\n", false);
	return ;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	add_instr("pb\n", false);
	return ;
}

void	push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (dir == 1)
			pb(stack_a, stack_b);
		else if (dir == -1)
			pa(stack_a, stack_b);
		i++;
	}
	return ;
}
