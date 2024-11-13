/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:12:23 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/13 09:04:41 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b);
void	rsort(t_list **stack_a, t_list **stack_b, int pivot);

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	pivot;

	pivot = (int)(8 * sizeof(int));
	while ((((int)ft_lstmax(stack_a, INT)) >> pivot) & 0)
		pivot--;
	printf("pivot = %i vs %i", pivot, (int)(8 * sizeof(int)));
	rsort(stack_a, stack_b, pivot);
}

void	rsort(t_list **stack_a, t_list **stack_b, int pivot)
{
	int i;

	while (pivot < (int)(8 * sizeof(int)))
	{	
		i = 0;
		while (i < ft_lstsize(*stack_a))
		{
			printf("i = %i\n", i);
			if ((get_n(stack_a, 0) >> pivot) & 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			printf("HELLO ?\n");
			i++;
		}
		push_bloc(stack_a, stack_b, ft_lstsize(*stack_b), -1);
		printf("PIVOT IS %i\n", pivot);
		print_list(stack_a, stack_b);
		pivot--;
	}
}
