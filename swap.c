/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:19:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/10 15:49:22 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	swap(t_list **stack)
{
	void	*tmp;

	if (!stack || !*stack || ft_lstsize(*stack) < 2)
		exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
	tmp = (((*stack)->next)->content);
	(((*stack)->next)->content) = ((*stack)->content);
	((*stack)->content) = tmp;
	return ;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	//write(1, "sa\n", 3);
	return ;
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	//write(1, "sb\n", 3);
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	//(1, "ss\n", 3);
	return ;
}
