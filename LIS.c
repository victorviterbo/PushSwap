/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:12 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/14 17:37:52 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_list	*get_lis(t_list **stack_a, int *len);
int		compute_cost(t_list **stack_a, t_list **stack_b, int pos);
void	do_move(t_list **stack_a, t_list **stack_b);

t_list	*get_lis(t_list **stack_a, int *len)
{
	int		i;
	int		last;
	int		rcase;
	t_list	*start;

	i = 1;
	*len = 1;
	last = 1;
	while (i < ft_lstsize(*stack_a))
	{
		last = (get_n(stack_a, i) > get_n(stack_a, i - 1)) * last + 1;
		if (last > *len)
		{
			*len = last;
			start = ft_lst_getn(stack_a, i - *len + 1);
		}
	}
	rcase = get_rcase(stack_a, stack_b, i, pos);
	return (start);
}

void	do_move(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	cost;
	int	min_cost;
	int	best_i;

	i = 0;
	min_cost = -1;
	while (i < ft_lstsize(*stack_b))
	{
		if (compute_cost(stack_a, stack_b, i) < min_cost)
		{
			min_cost = compute_cost(stack_a, stack_b, i);
			best_i = i;
		}
		i++;
	}
}

int	compute_cost(t_list **stack_a, t_list **stack_b, int pos)
{
	int	cost;
	int	i;
	int	rcase;

	i = 0;
	while (get_n(stack_a, i + 1) < get_n(stack_b, pos))
		i++;
	rcase = get_rcase(stack_a, stack_b, i, pos);
	if (rcase == 0)
		return (ft_max(i, pos));
	else if (rcase == 1)
		return (ft_max(i, ft_lstsize(*stack_b) - pos));
	else if (rcase == 2)
		return (ft_max(ft_listsize(*stack_a) - i, pos));
	else
		return (ft_max(ft_listsize(*stack_a) - i, ft_lstsize(*stack_b) - pos));
}

int	get_rcase(t_list **stack_a, t_list **stack_b, int i, int pos)
{
	if (2 * i < ft_lstsize(*stack_a) && 2 * pos < ft_lstsize(*stack_b))
		return (0);
	else if (2 * i <= ft_lstsize(*stack_a) && 2 * pos >= ft_lstsize(*stack_b))
		return (1);
	else if (2 * i >= ft_lstsize(*stack_a) && 2 * pos <= ft_lstsize(*stack_b))
		return (2);
	else
		return (3);
}
