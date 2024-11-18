/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:45:15 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/18 23:24:08 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **stack_1, t_list **stack_2);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir);

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*next_node_a;
	t_list	*next_node_b;

	if (!stack_1 || !stack_2)
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	else if (!*stack_2 || ft_lstsize(*stack_2) < 1)
		return ;
	if (!*stack_1)
		next_node_a = NULL;
	else
		next_node_a = *stack_1;
	*stack_1 = *stack_2;
	next_node_b = (*stack_2)->next;
	(*stack_1)->next = next_node_a;
	*stack_2 = next_node_b;
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
