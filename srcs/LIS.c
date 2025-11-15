/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:12 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/15 12:44:11 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

bool	*get_lis(t_list **stack_a);
int		*lst2arr(t_list **stack);
void	set_endpoint(int *lis_lens, int *arra, int n);
int		find_max(int *arr, int n);
bool	*propagate_backward(int *lis_lens, int *arra, int best, int n);

bool	*get_lis(t_list **stack_a)
{
	int		n;
	int		best;
	int		*arra;
	int		*lis_lens;
	bool	*to_keep;

	n = ft_lstsize(*stack_a);
	arra = lst2arr(stack_a);
	lis_lens = ft_calloc(2 * n, sizeof(int));
	set_endpoint(lis_lens, arra, n);
	best = find_max(lis_lens, n);
	to_keep = propagate_backward(lis_lens, arra, best, n);
	free(lis_lens);
	free(arra);
	return (to_keep);
}

int	*lst2arr(t_list **stack)
{
	int		i;
	int		*arr;
	t_list	*current;

	i = 0;
	arr = ft_calloc(ft_lstsize(*stack), sizeof(int));
	current = *stack;
	while (current)
	{
		*(arr + i) = current->i;
		i++;
		current = current->next;
	}
	return (arr);
}

void	set_endpoint(int *lis_lens, int *arra, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2 * n)
	{
		lis_lens[i] = 1;
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < i + n)
		{
			if (arra[i % n] <= arra[j % n])
				lis_lens[j] = ft_max(lis_lens[j], lis_lens[i] + 1);
			j++;
		}
		i++;
	}
	return ;
}

int	find_max(int *arr, int n)
{
	int	i;
	int	j;

	i = 2 * n - 1;
	j = 0;
	while (i + 1)
	{
		if (arr[i] > arr[j])
			j = i;
		i--;
	}
	return (j);
}

bool	*propagate_backward(int *lis_lens, int *arra, int best, int n)
{
	int		i;
	int		last;
	bool	*to_keep;

	to_keep = ft_calloc(n, sizeof(bool));
	to_keep[best % n] = 1;
	i = best;
	last = lis_lens[best];
	best--;
	if (best == 0)
		best += n;
	while (ft_abs(i - best) < n)
	{
		if (arra[best % n] <= arra[i % n] && lis_lens[best] == last - 1)
		{
			to_keep[best % n] = true;
			last--;
		}
		if (best == 0)
			best += 2 * n;
		best--;
	}
	return (to_keep);
}
