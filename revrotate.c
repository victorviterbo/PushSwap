/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:58:46 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/17 22:19:58 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	revrotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	revrotate_i(t_list **stack_1, t_list **stack_2, int n, char ab);

void	revrotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (!stack || !*stack)
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
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
	add_instr("rra\n", false);
	return ;
}

void	rrb(t_list **stack_b)
{
	revrotate(stack_b);
	add_instr("rrb\n", false);
	return ;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	add_instr("rrr\n", false);
	return ;
}

void	revrotate_i(t_list **stack_1, t_list **stack_2, int n, char ab)
{
	int	i;

	i = 0;
	if (!stack_1 || !*stack_1)
		return ;
	if (ft_lstsize(*stack_1) < (int)n * 2 && ab != 'r')
		return (rotate_i(stack_1, stack_2, ft_lstsize(*stack_1) - n, ab));
	while (i < n)
	{
		if (ab == 'a')
			rra(stack_1);
		else if (ab == 'b')
			rrb(stack_1);
		else if (ab == 'r')
			rrr(stack_1, stack_2);
		i++;
	}
	return ;
}
