/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:12 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/17 12:31:50 by vviterbo         ###   ########.fr       */
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
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	printf("coucou !\n");
	print_list(stack_a, stack_b);
	smart_push(stack_a, stack_b);
	printf("coucou 2 !\n");
	print_list(stack_a, stack_b);
	do_move(stack_a, stack_b);
	print_list(stack_a, stack_b);
	goto_val(stack_a, 'a', ft_lstmin(stack_a, INT), false);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return (0);
}

int	get_lis(t_list **stack_a, int *len)
{
	int	i;
	int	last;
	int	best_i;

	i = 1;
	*len = 1;
	last = 1;
	best_i = 0;
	while (i < 2 * ft_lstsize(*stack_a))
	{
		last = (get_n(stack_a, (i - 1) % ft_lstsize(*stack_a))
				< get_n(stack_a, i % ft_lstsize(*stack_a))) * last + 1;
		if (last > *len)
		{
			*len = last;
			best_i = i - (*len - 1);
		}
		printf("%i: %i; %i vs %i; best_i = %i, best_len = %i\n", i, last, get_n(stack_a, (i - 1) % ft_lstsize(*stack_a)), get_n(stack_a, i % ft_lstsize(*stack_a)), best_i, *len);
		i++;
	}
	//*len -= 1;
	best_i = (best_i + ft_lstsize(*stack_a)) % ft_lstsize(*stack_a);
	printf("\n\nbest_i ===== %i\n\n", best_i);
	return (best_i);
}

void	do_move(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		best_i;

	while (*stack_b)
	{
		i = 0;
		best_i = 0;
		while (i < ft_lstsize(*stack_b))
		{
			if (ft_abs(compute_cost(stack_a, stack_b, i))
				< ft_abs(compute_cost(stack_a, stack_b, best_i)))
				best_i = i;
			i++;
		}
		printf("enter smart rotate\n");
		print_list(stack_a, stack_b);
		smart_rotate(stack_a, stack_b, best_i);
		printf("exit smart rotate\n");
		print_list(stack_a, stack_b);
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

	min = 0;
	if (get_n(stack_b, pos) < ft_lstmin(stack_a, INT) || get_n(stack_b, pos) > ft_lstmax(stack_a, INT))
	{
		while (min < ft_lstsize(*stack_a) && (get_n(stack_a, (min + 1) % ft_lstsize(*stack_a)) > get_n(stack_a, min)))
			min++;
	}
	else
	{
		while (min < ft_lstsize(*stack_a) && !(
				get_n(stack_a, (ft_lstsize(*stack_a) + min - 1) % ft_lstsize(*stack_a)) < get_n(stack_b, pos))
				&& get_n(stack_b, pos) < get_n(stack_a, min % ft_lstsize(*stack_a)))
			min++;
		min++;
	}
	printf("min = %i == %i\n", min, min == ft_lstsize(*stack_a) + 2);
	printf("WTF ? %i\n", get_n(stack_a, (ft_lstsize(*stack_a) + min - 1) % ft_lstsize(*stack_a)));
	printf("%i && %i < %i && %i < %i\n", min < ft_lstsize(*stack_a), get_n(stack_a, (ft_lstsize(*stack_a) + min - 1) % ft_lstsize(*stack_a)), get_n(stack_b, pos), get_n(stack_b, pos), get_n(stack_a, min % ft_lstsize(*stack_a)));
	min %= ft_lstsize(*stack_a);
	printf("min = %i\n", min);
	forward = ft_max(min, pos);
	backward = ft_max(ft_lstsize(*stack_a) - min, ft_lstsize(*stack_b) - pos);
	zigzag_forward = 2 * pos + (ft_lstsize(*stack_a) - min);
	zigzag_backward = 2 * (ft_lstsize(*stack_b) - pos) + min;
	printf("forward = %i, backward = %i, zigzag_forward = %i, zigzag_backward = %i\n", forward, backward, zigzag_forward, zigzag_backward);
	printf("\n\n");
	printf("2 * pos + (ft_lstsize(*stack_a) - min) = 2 * %i + (%i - %i) = %i\n", pos, ft_lstsize(*stack_a), min, 2 * pos + (ft_lstsize(*stack_a) - min));
	printf("\n\n");
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
	printf("recompute cost\n");
	n = compute_cost(stack_a, stack_b, best_i);
	printf("recomputed cost\n");
	rev = n < 0;
	n = ft_abs(n);
	b_value = get_n(stack_b, best_i);
	printf("n = %i, best_i = %i, rev = %i\n", n, best_i, rev);
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
	printf("Doing final rotations\n");
	print_list(stack_a, stack_b);
	rotate_i(stack_b, best_i, 'b');
	print_list(stack_a, stack_b);
	goto_val(stack_a, 'a', b_value, false);
	print_list(stack_a, stack_b);
	return ;
}

void	smart_push(t_list **stack_a, t_list **stack_b)
{
	int	lis_start;
	int	*lis_len;

	lis_len = ft_calloc(1, sizeof(int));
	printf("-1\n");
	lis_start = get_lis(stack_a, lis_len);
	printf("0\n");
	printf("lis_start = %i, lis_len = %i, size = %i\n", lis_start, *lis_len, ft_lstsize(*stack_a));
	if (*lis_len == ft_lstsize(*stack_a))
		return (rotate_i(stack_a, lis_start, 'a'));
	printf("1\n");
	push_bloc(stack_a, stack_b, lis_start, 1);
	printf("2\n");
	rotate_i(stack_a, *lis_len, 'a');
	printf("3\n");
	printf("%i\n", ft_lstsize(*stack_a) - *lis_len);
	push_bloc(stack_a, stack_b, ft_lstsize(*stack_a) - *lis_len, 1);
	printf("4\n");
	return ;
}
