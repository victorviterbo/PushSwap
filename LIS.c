/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:12 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/17 19:23:10 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		main(int argc, char *argv[]);
void	get_lis(t_list **stack_a, int *to_keep);
void	do_move(t_list **stack_a, t_list **stack_b);
int		compute_cost(t_list **stack_a, t_list **stack_b, int pos);
int		get_rcase(t_list **stack_a, t_list **stack_b, int i, int pos);
void	smart_rotate(t_list **stack_a, t_list **stack_b, int best_i);
void	smart_push(t_list **stack_a, t_list **stack_b);


int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = parse_input(argc, argv);
	stack_b = ft_calloc(1, sizeof(t_list *));
	exit_gracefully(stack_a, stack_b, -1);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	if (ft_lstsize(*stack_a) <= 5)
		minisort(stack_a, stack_b);
	smart_push(stack_a, stack_b);
	do_move(stack_a, stack_b);
	goto_val(stack_a, 'a', ft_lstmin(stack_a, INT), false);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return (0);
}

void	smart_push(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	*to_keep;
	int	size_a;

	i = 0;
	to_keep = ft_calloc(ft_lstsize(*stack_a), sizeof(int));
	get_lis(stack_a, to_keep);
	i = 0;
	size_a = ft_lstsize(*stack_a);
	while (i < size_a)
	{
		if (to_keep[i] == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	return ;
}

void	get_lis(t_list **stack_a, int *to_keep)
{
	int	i;
	int	j;
	int	n;
	int	**arr;
	int	*darr;
	int last;

	i = 0;
	j = 0;
	n = ft_lstsize(*stack_a);
	arr = ft_calloc(2 * n, (sizeof(int *)));
	while (i < 2 * n)
	{
		arr[i] = ft_calloc(2 * n, (sizeof(int)));
		i++;
	}
	i = 0;
	while (i < 2 * n)
	{
		j = 0;
		while (j < 2 * n)
		{
			arr[i][j] = (get_n(stack_a, i % n) <= get_n(stack_a, j % n));
			j++;
		}
		i++;
	}
	darr = ft_calloc(2 * n, sizeof(int));
	i = 0;
	while (i < 2 * n)
	{
		darr[i] = 1;
		i++;
	}
	i = 0;
	while (i < 2 * n)
	{
		j = i + 1;
		while (j < i + n)
		{
			if (arr[i][j])
				darr[j] = ft_max(darr[j], darr[i] + 1);
			j++;
		}		
		i++;
	}
	i = 0;
	i = 2 * n - 1;
	j = 0;
	while (i + 1)
	{
		if (darr[i] > darr[j])
			j = i;
		i--;
	}
	to_keep[j % n] = 1;
	i = j;
	last = darr[j];
	j--;
	while (ft_abs(i - j) < n)
	{
		if (arr[j][i] && darr[j] == last - 1)
		{
			to_keep[j % n] = 1;
			last--;
		}
		if (j == 0)
			j += 2 * n;
		j--;
	}
	i = 0;
	return ;
}

void	do_move(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		best_i;
	int		min_cost;

	while (*stack_b)
	{
		i = 1;
		best_i = 0;
		min_cost = ft_abs(compute_cost(stack_a, stack_b, 0));
		while (i < ft_lstsize(*stack_b))
		{
			if (ft_abs(compute_cost(stack_a, stack_b, i))
				< min_cost)
			{
				best_i = i;
				min_cost = ft_abs(compute_cost(stack_a, stack_b, i));
			}
			i++;
		}
		smart_rotate(stack_a, stack_b, best_i);
		pa(stack_a, stack_b);
	}
	return ;
}

int	compute_cost(t_list **stack_a, t_list **stack_b, int pos)
{
	int	forward;
	int	backward;
	int	zigzag_forward;
	int	zigzag_backward;
	int	min;

	min = goto_val(stack_a, 'a', get_n(stack_b, pos), true);
	min %= ft_lstsize(*stack_a);
	forward = ft_max(min, pos);
	backward = ft_max(ft_lstsize(*stack_a) - min, ft_lstsize(*stack_b) - pos);
	zigzag_forward = 2 * pos + (ft_lstsize(*stack_a) - min);
	zigzag_backward = 2 * (ft_lstsize(*stack_b) - pos) + min;
	min = ft_min(ft_min(forward, backward),
			ft_min(zigzag_forward, zigzag_backward));
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
	int		b_value;
	bool	rev;

	i = 0;
	n = compute_cost(stack_a, stack_b, best_i);
	rev = n < 0;
	n = ft_abs(n);
	b_value = get_n(stack_b, best_i);
	while (!rev && best_i && !(get_n(stack_a, 0) > b_value
			&& get_n(stack_a, ft_lstsize(*stack_a) - 1) < b_value))
	{
		rr(stack_a, stack_b);
		best_i--;
		i++;
	}
	while (rev && best_i && !(get_n(stack_a, 0) > b_value
			&& get_n(stack_a, ft_lstsize(*stack_a) - 1) < b_value))
	{
		rrr(stack_a, stack_b);
		best_i = (best_i + 1) % ft_lstsize(*stack_b);
		i++;
	}
	rotate_i(stack_b, best_i, 'b');
	goto_val(stack_a, 'a', b_value, false);
	return ;
}
