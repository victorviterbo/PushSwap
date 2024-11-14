/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:12 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/14 23:48:26 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_list	*get_lis(t_list **stack_a, int *len);
void	do_move(t_list **stack_a, t_list **stack_b);
int		compute_cost(t_list **stack_a, t_list **stack_b, int pos);
int		get_rcase(t_list **stack_a, t_list **stack_b, int i, int pos);

t_list	*get_lis(t_list **stack_a, int *len)
{
	int		i;
	int		last;
	int		best_i;

	i = 1;
	*len = 1;
	last = 1;
	while (i < ft_lstsize(*stack_a))
	{
		last = (get_n(stack_a, i) > get_n(stack_a, i - 1)) * last + 1;
		if (last > *len)
		{
			*len = last;
			best_i = i - *len + 1;
		}
	}
	return (best_i);
}

void	do_move(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	cost;
	int	min_cost;
	int	best_i;

	i = 0;
	min_cost = -1;
	while (i < ft_lstsize(*stack_b))
	{
		j = 0;
		while (get_n(stack_a, j + 1) < get_n(stack_b, i))
			j++;
		cost = i % (ft_lstsize(stack_b) / 2) + j % (ft_lstsize(stack_b) / 2);
		min_cost = min_cost * (cost > min_cost) + cost * (cost < min_cost);
		best_i = best_i * (cost > min_cost) + i * (cost < min_cost);
		i++;
	}
	j = 0;
	while (get_n(stack_a, j + 1) < get_n(stack_b, best_i))
		j++;
	if (best_i < )
	while (get_n(stack_a, i + 1) < get_n(stack_b, best_i))
		i++;
	rcase = get_rcase(stack_a, stack_b, i, best_i);
	if (rcase == 0)
	{
		
	}
}

int	compute_cost(t_list **stack_a, t_list **stack_b, int pos)
{
	int	rev_pos;
	int	rev_i;
	int	i;

	i = 0;
	while (get_n(stack_a, i + 1) < get_n(stack_b, pos)
		&& i + 1 < ft_lstsize(*stack_a))
		i++;
	rev_pos = pos - (int)(ft_lstsize(*stack_b) / 2) + 1;
	rev_i = ft_abs((i - (int)(ft_lstsize(*stack_a) / 2) + 1 - rev_pos)
			% ft_lstsize(*stack_a));
	i = (i - pos) % ft_lstsize(*stack_a);
	if (rcase == 0)
		return (ft_min(ft_min(i, pos), pos + ft_max(pos - i, i - pos)));
	else if (rcase == 1)
		return (ft_max(i, ft_lstsize(*stack_b) - pos));
	else if (rcase == 2)
		return (ft_max(ft_listsize(*stack_a) - i, pos));
	else
		return (ft_max(ft_listsize(*stack_a) - i, ft_lstsize(*stack_b) - pos));
}

int	get_rcase(t_list **stack_a, t_list **stack_b, int i, int pos)
{
	int	rev_pos;
	int	rev_i;
	int	rot;

	rev_pos = pos - (int)(ft_lstsize(*stack_b) / 2) + 1;
	rev_i = ft_abs((i - (int)(ft_lstsize(*stack_a) / 2) + 1 - rev_pos)
			% ft_lstsize(*stack_a));
	i = (i - pos) % ft_lstsize(*stack_a);
}


	
	if (rev_i < 0)
		pos = ft_min(-rev_pos, pos);
	if ()
	rot = rev_pos +  - (int)(ft_lstsize(*stack_a) / 2) + 1);
	if (2 * i < ft_lstsize(*stack_a) && 2 * pos < ft_lstsize(*stack_b))
		return (ft_max(ft_listsize(*stack_a) - i, pos));
	else if (2 * i <= ft_lstsize(*stack_a) && 2 * pos >= ft_lstsize(*stack_b))
		return (1);
	else if (2 * i >= ft_lstsize(*stack_a) && 2 * pos <= ft_lstsize(*stack_b))
		return (2);
	else
		return (3);
}
