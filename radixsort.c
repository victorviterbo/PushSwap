/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:12:23 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/13 13:15:33 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b);
void	rsort(t_list **stack_a, t_list **stack_b, int pivot);
bool	radix_ncmp(int int1, int int2, int n);

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	pivot;

	pivot = (int)(8 * sizeof(int));
	while (((((int)ft_lstmax(stack_a, INT)) >> pivot) & 1) == 0)
		pivot--;
	rsort(stack_a, stack_b, pivot);
}

void	rsort(t_list **stack_a, t_list **stack_b, int pivot)
{
	int	i;
	int	bloc_prefix;
	int	b_size;
	int	a_size;

	while (pivot + 1)
	{	
		i = 0;
		bloc_prefix = get_n(stack_a, 0);
		while (i < ft_lstsize(*stack_a))
		{
			a_size = ft_lstsize(*stack_a);
			while (radix_ncmp(get_n(stack_a, 0), bloc_prefix, pivot + 1) && i < a_size)
			{
				if (((get_n(stack_a, 0) >> pivot) & 1) == 1)
					pb(stack_a, stack_b);
				else
					ra(stack_a);
				i++;
			}
			b_size = ft_lstsize(*stack_b);
			push_bloc(stack_a, stack_b, b_size, -1);
			rotate_i(stack_a, b_size, 'a');
			bloc_prefix = get_n(stack_a, 0);
		}
		pivot--;
	}
}

bool	radix_ncmp(int int1, int int2, int n)
{
	return (int1 >> n == int2 >> n);
}
