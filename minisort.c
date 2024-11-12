/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:34:01 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/12 17:01:39 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	minisort(t_list **stack_a, t_list **stack_b);
void	msort3(t_list **stack_a, t_list **stack_b);
void	msort4(t_list **stack_a, t_list **stack_b);
void	msort5(t_list **stack_a, t_list **stack_b);

void	minisort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		usort_swap(*stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		msort3(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		msort4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		msort5(stack_a, stack_b);
	return ;
}

void	msort3(t_list **stack_a, t_list **stack_b)
{
	int	int1;
	int	int2;
	int	int3;

	int1 = *(int *)((ft_lstgetn(stack_a, 0))->content);
	int2 = *(int *)((ft_lstgetn(stack_a, 1))->content);
	int3 = *(int *)((ft_lstgetn(stack_a, 2))->content);
	if (int1 < int2 && int1 < int3)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (int2 < int1 && int2 < int3)
	{
		sa(stack_a);
		ra(stack_a);
		usort_swap(stack_a, 'a');
		rra(stack_a);
	}
	else
	{
		usort_swap(stack_a, 'a');
		rra(stack_a);
	}
}
