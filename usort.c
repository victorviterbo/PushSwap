/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:35:39 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/11 15:30:09 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	usort(t_list **stack_a, t_list **stack_b);
void	usort1(t_list **stack_a, t_list **stack_b, int order);
void	usort2(t_list **stack_a, t_list **stack_b, int order);
void	usort3(t_list **stack_a, t_list **stack_b, int order);

void	usort(t_list **stack_a, t_list **stack_b)
{
	int	int1;
	int	int2;
	int	int3;

	int1 = ft_parse_as((*stack_a)->content, INT);
	int2 = ft_parse_as((*stack_a)->next->content, INT);
	int3 = ft_parse_as((*stack_a)->next->next->content, INT);
	if (int1 < int2 && int1 < int3)
		usort1(stack_a, stack_b, (int2 > int3));
	else if (int2 < int1 && int2 < int3)
		usort2(stack_a, stack_b, (int1 > int3));
	else if (int3 < int1 && int3 < int2)
		usort3(stack_a, stack_b, (int1 > int2));
	return ;
}

void	usort1(t_list **stack_a, t_list **stack_b, int order)
{
	ra(stack_a);
	if (order == 1)
		sa(stack_a);
	rotate_i(stack_a, 2, 'a');
	(void)stack_b;
	return ;
}

void	usort2(t_list **stack_a, t_list **stack_b, int order)
{
	sa(stack_a);
	ra(stack_a);
	if (order == 1)
		sa(stack_a);
	rotate_i(stack_a, 2, 'a');
	(void)stack_b;
	return ;
}

void	usort3(t_list **stack_a, t_list **stack_b, int order)
{
	pb(stack_a, stack_b);
	sa(stack_a);
	ra(stack_a);
	if (order == 0)
		pa(stack_a, stack_b);
	ra(stack_a);
	if (order == 1)
		pa(stack_a, stack_b);
	ra(stack_a);
	return ;
}
