/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:58:46 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/17 22:11:42 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rotate_i(t_list **stack_1, t_list **stack_2, int n, char ab);

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack)
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstlast(*stack)->next = tmp;
	tmp->next = NULL;
	return ;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	add_instr("ra\n", false);
	return ;
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	add_instr("rb\n", false);
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	add_instr("rr\n", false);
	return ;
}

void	rotate_i(t_list **stack_1, t_list **stack_2, int n, char ab)
{
	int	i;

	i = 0;
	if (!stack_1 || !*stack_1)
		return ;
	if (ft_lstsize(*stack_1) < (int)n * 2 && ab != 'r')
		return (revrotate_i(stack_1, stack_2, ft_lstsize(*stack_1) - n, ab));
	while (i < n)
	{
		if (ab == 'a')
			ra(stack_1);
		else if (ab == 'b')
			rb(stack_1);
		else if (ab == 'r')
			rr(stack_1, stack_2);
		i++;
	}
	return ;
}
