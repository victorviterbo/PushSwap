/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:19:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/21 13:54:15 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	sa(t_list **stack_a)
{
	void	*tmp;

	tmp = (((*stack_a)->next)->content);
	(((*stack_a)->next)->content) = ((*stack_a)->content);
	((*stack_a)->content) = tmp;
	return ;
}

void	sb(t_list **stack_b)
{
	void	*tmp;

	tmp = (((*stack_b)->next)->content);
	(((*stack_b)->next)->content) = ((*stack_b)->content);
	((*stack_b)->content) = tmp;
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	return ;
}