/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:12 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/15 10:12:26 by vviterbo         ###   ########.fr       */
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
	int		i;
	int		best_i;

	i = 0;
	best_i = 0;
	while (i < ft_lstsize(*stack_b))
	{
		if (ft_abs(compute_cost(stack_a, stack_b, i))
			< ft_abs(compute_cost(stack_a, stack_b, best_i)))
			best_i = i;
		i++;
	}
	i = 0;
	if (ft_abs(compute_cost(stack_a, stack_b, best_i)) < 0)
	{
		
	}
}

int	compute_cost(t_list **stack_a, t_list **stack_b, int pos)
{
	int	i;
	int forward;
	int	backward;
	int	zigzag_forward;
	int	zigzag_backward;
	int	min;

	i = 0;
	while (get_n(stack_a, i + 1) < get_n(stack_b, pos)
		&& i + 1 < ft_lstsize(*stack_a))
		i++;
	forward = t_max(i, pos);
	backward = ft_max(ft_lstsize(*stack_a) - i, ft_lstsize(*stack_b) - pos);
	zigzag_forward = 2 * pos + (ft_lstsize(*stack_a) - i);
	zigzag_backward = 2 * (ft_lstsize(*stack_b) - pos) + i;
	min = ft_min(ft_min(forward, backward), ft_min(zigzag_forward, zigzag_backward));
	if (min == forward || min == zigzag_forward)
		return (min);
	else if (min == backward || min == zigzag_backward)
		return (-min);
	else
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return (0);
}

void	smart_rotate(t_list **stack_a, t_list **stack_b, int best_i)
{
	int		i;
	int		n;
	bool	rev;

	i = 0;
	n = compute_cost(stack_a, stack_b, best_i);
	rev = n < 0;
	n = ft_abs(n);
	while (!rev && get_n(stack_a, i + 1) < get_n(stack_b, best_i) && best_i)
	{
		rr(stack_a, stack_b);
		best_i--;
		i++;
	}
	while (rev && get_n(stack_a, i) > get_n(stack_b, best_i) && best_i)
	{
		rrr(stack_a, stack_b);
		best_i = (best_i + 1) % ft_lstsize(*stack_b);
		i++;
	}
	rotate_i(stack_a, stack_b, best_i, 'b');
	rotate_i(stack_a, stack_b, n - best_i, 'a');
	return ;
}
