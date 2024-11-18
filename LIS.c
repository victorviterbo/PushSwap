/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:12 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/18 22:52:31 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		*get_lis(t_list **stack_a);
int		*lst2arr(t_list **stack);
void	set_endpoint(int *darr, int *arra, int n);
int		find_max(int *arr, int n);
int		*propagate_backward(int *darr, int *arra, int best, int n);

int	*get_lis(t_list **stack_a)
{
	int	n;
	int	best;
	int	*arra;
	int	*darr;
	int	*to_keep;

	n = ft_lstsize(*stack_a);
	arra = lst2arr(stack_a);
	darr = ft_calloc(2 * n, sizeof(int));
	set_endpoint(darr, arra, n);
	best = find_max(darr, n);
	to_keep = propagate_backward(darr, arra, best, n);
	free(darr);
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

void	set_endpoint(int *darr, int *arra, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2 * n)
	{
		darr[i] = 1;
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < i + n)
		{
			if (arra[i % n] <= arra[j % n]) //#TODO add i != j ?
				darr[j] = ft_max(darr[j], darr[i] + 1);
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
	return (i);
}

int	*propagate_backward(int *darr, int *arra, int best, int n)
{
	int	i;
	int	last;
	int	*to_keep;

	to_keep = ft_calloc(n, sizeof(int));
	to_keep[best % n] = 1;
	i = best;
	last = darr[best];
	best--;
	if (best == 0)
		best += n;
	while (ft_abs(i - best) < n)
	{
		if (arra[best % n] <= arra[i % n] && darr[best] == last - 1)
		{
			to_keep[best % n] = 1;
			last--;
		}
		if (best == 0)
			best += 2 * n;
		best--;
	}
	return (to_keep);
}
