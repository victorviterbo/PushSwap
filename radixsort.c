/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:12:23 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/18 12:29:17 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b);
void	rsort(t_list **stack_a, t_list **stack_b, int pivot);
bool	radix_ncmp(int int1, int int2, int n);

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	pivot;

	pivot = (int)(8 * sizeof(int)) - 1;
	while ((((ft_lstmaxi(stack_a)) >> pivot) & 1) == 0)
		pivot--;
	rsort(stack_a, stack_b, pivot);
	return ;
}

void	rsort(t_list **stack_a, t_list **stack_b, int pivot)
{
	int	i;
	int	j;
	int	i_rot;
	int	bloc_prefix;
	int	b_size;
	int	a_size;

	while (pivot + 1 > 0)
	{	
		i = 0;
		bloc_prefix = get_n(stack_a, 0);
		i_rot = 0;
		while (i < ft_lstsize(*stack_a))
		{
			a_size = ft_lstsize(*stack_a);
			while (radix_ncmp(get_n(stack_a, i_rot), bloc_prefix, pivot + 1) && i < a_size)
			{
				if (((get_n(stack_a, i_rot) >> pivot) & 1) == 1)
				{
					rotate_i(stack_a, i_rot, 'a');
					i_rot = 0;
					pb(stack_a, stack_b);
				}
				else
					i_rot++;
				i++;
			}
			rotate_i(stack_a, i_rot, 'a');
			i_rot = 0;
			b_size = ft_lstsize(*stack_b);
			if (pivot == 0)
			{
				push_bloc(stack_a, stack_b, b_size, -1);
				rotate_i(stack_a, b_size, 'a');
				bloc_prefix = get_n(stack_a, 0);
				break ;
			}
			j = 0;
			i_rot = 0;
			while (j < b_size)
			{
				if (((get_n(stack_b, 0) >> (pivot - 1)) & 1) == 1)
				{
					rotate_i(stack_b, i_rot, 'b');
					i_rot = 0;
					pa(stack_a, stack_b);
				}
				else
					i_rot++;
				j++;
			}
			rotate_i(stack_b, i_rot, 'b');
			push_bloc(stack_a, stack_b, ft_lstsize(*stack_b), -1);
			rotate_i(stack_a, b_size, 'a');
			bloc_prefix = get_n(stack_a, 0);
		}
		pivot -= 2;
	}
}

void	radix_insert(t_list **stack_a, t_list **stack_b, int pivot, int dir)
{
	int	i;
	int	i_rot;
	int	size_src;
	int	size_dest;
	int	bloc_prefix;

	i_rot = 0;
	if (dir == 1)
	{
		bloc_prefix = get_n(stack_a, i_rot);
		size_src = ft_lstsize(*stack_a);
	}
	else if (dir == -1)
	{
		bloc_prefix = get_n(stack_b, i_rot);
	}
	while (radix_ncmp(get_n(stack_a, i_rot), bloc_prefix, pivot + 1) && i < a_size)
	{
		if (((get_n(stack_a, i_rot) >> pivot) & 1) == 1)
		{
			rotate_i(stack_a, i_rot, 'a');
			i_rot = 0;
			pb(stack_a, stack_b);
		}
		else
			i_rot++;
		i++;
	}
}


bool	radix_ncmp(int int1, int int2, int n)
{
	return (int1 >> n == int2 >> n);
}
