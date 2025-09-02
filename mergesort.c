/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2025/09/02 11:38:41 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	init(t_list **stack_a, t_list **stack_b);
void	merge(t_list **stack_a, t_list **stack_b, int size_a);
int		insert(t_list **stack_a, t_list **stack_b, int size_a);
void	sort(t_list **stack_a, t_list **stack_b, int n);

void	init(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	len;

	len = ft_lstsize(*stack_a);
	i = 0;
	while (i + 1 < len)
	{
		usort(stack_a, stack_b, ft_min(5, len - i));
		i += 5;
	}
	if (len % 5 == 1)
		ra(stack_a);
	return ;
}

void	merge(t_list **stack_a, t_list **stack_b, int size_a)
{
	while (*stack_b)
	{
		if (ft_lstsize(*stack_b) > 1)
			rrb(stack_b);
		size_a -= insert(stack_a, stack_b, size_a);
	}
	rotate_i(stack_a, NULL, size_a, 'a');
	return ;
}

int	insert(t_list **stack_a, t_list **stack_b, int size_a)
{
	int		stb;
	int		i;

	i = 0;
	stb = (*stack_b)->i;
	if (stb < (*stack_a)->i)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		return (0);
	}
	while (stb > (*stack_a)->i && i < size_a)
	{
		ra(stack_a);
		i++;
	}
	pa(stack_a, stack_b);
	ra(stack_a);
	return (i);
}

void	sort(t_list **stack_a, t_list **stack_b, int n)
{
	int	lenleft;

	while (n < ft_lstsize(*stack_a))
	{
		lenleft = ft_lstsize(*stack_a);
		while (lenleft > n)
		{
			push_bloc(stack_a, stack_b, n, 1);
			merge(stack_a, stack_b, (int)ft_min(lenleft - n, n));
			lenleft -= (int)ft_min(lenleft, 2 * n);
			if (minichecker(stack_a, stack_b))
				exit_gracefully(NULL, NULL, EXIT_SUCCESS);
		}
		rotate_i(stack_a, NULL, lenleft, 'a');
		n *= 2;
	}
	return ;
}
