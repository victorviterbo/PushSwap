/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:19:47 by vviterbo          #+#    #+#             */
/*   Updated: 2025/09/02 11:38:42 by victorviter      ###   ########.fr       */
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

	if (!stack)
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	if (!*stack || ft_lstsize(*stack) < 2)
		return ;
	tmp = (((*stack)->next)->content);
	(((*stack)->next)->content) = ((*stack)->content);
	((*stack)->content) = tmp;
	return ;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	add_instr("sa\n", false);
	return ;
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	add_instr("sb\n", false);
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	add_instr("ss\n", false);
	return ;
}
