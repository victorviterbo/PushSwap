/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:12 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/15 11:39:23 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		main(int argc, char *argv[]);
int		get_lis(t_list **stack_a, int *len);
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
	print_list(stack_a, stack_b);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	printf("HELLO\n");
	smart_push(stack_a, stack_b);
	printf("OK ?\n");
	print_list(stack_a, stack_b);
	do_move(stack_a, stack_b);
	print_list(stack_a, stack_b);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return (0);
}

int	get_lis(t_list **stack_a, int *len)
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
		i++;
	}
	return (best_i);
}

void	do_move(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		best_i;

	i = 0;
	best_i = 0;
	while (ft_lstsize(*stack_b))
	{
		while (i < ft_lstsize(*stack_b))
		{
			if (ft_abs(compute_cost(stack_a, stack_b, i))
				< ft_abs(compute_cost(stack_a, stack_b, best_i)))
				best_i = i;
			i++;
		}
		i = 0;
		smart_rotate(stack_a, stack_b, best_i);
		pa(stack_a, stack_b);
	}
}

int	compute_cost(t_list **stack_a, t_list **stack_b, int pos)
{
	int	forward;
	int	backward;
	int	zigzag_forward;
	int	zigzag_backward;
	int	min;

	min = 0;
	while (get_n(stack_a, min + 1) < get_n(stack_b, pos)
		&& min + 1 < ft_lstsize(*stack_a))
		min++;
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
	rotate_i(stack_a, best_i, 'b');
	rotate_i(stack_a, n - best_i, 'a');
	return ;
}

void	smart_push(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	lis_start;
	int	lis_len;
	int	*lis_rev;

	lis_rev = ft_calloc(1, sizeof(int));
	lis_start = get_lis(stack_a, lis_rev);
	lis_len = *lis_rev - lis_start;
	*lis_rev = ft_lstsize(*stack_a) - *lis_rev + lis_start;
	i = 0;
	if (*lis_rev < lis_start)
	{
		while (i < *lis_rev)
		{
			rra(stack_a);
			i++;
		}
		printf("rev : i = %i\n", i);
		i = 0;
		while (i < lis_len)
		{
			pb(stack_a, stack_b);
			rra(stack_a);
			i++;
		}
	}
	else
	{
		while (i < lis_start)
		{
			ra(stack_a);
			i++;
		}
		printf("for : i = %i\n", i);
		i = 0;
		printf("for : lislen = %i\n", lis_len);
		while (i <= lis_len)
		{
			pb(stack_a, stack_b);
			i++;
		}
	}
	return ;
}
