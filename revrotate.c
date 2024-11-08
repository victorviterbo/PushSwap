/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:58:46 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/08 11:41:21 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	revrotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	revrotate_i(t_list **stack_a, size_t n);

void	revrotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (!stack || !*stack)
		exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = ft_lstlast(*stack);
	ft_lstlast(*stack)->next = *stack;
	current = *stack;
	while (current->next != tmp)
		current = current->next;
	current->next = NULL;
	(*stack) = tmp;
	return ;
}

void	rra(t_list **stack_a)
{
	revrotate(stack_a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_list **stack_b)
{
	revrotate(stack_b);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	write(1, "rrr\n", 4);
	return ;
}

void	revrotate_i(t_list **stack_a, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		rra(stack_a);
		i++;
	}
	return ;
}
