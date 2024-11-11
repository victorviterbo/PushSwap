/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/11 12:33:17 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		main(int argc, char *argv[]);
void	init(t_list **stack_a, t_list **stack_b);
void	merge(t_list **stack_a, t_list **stack_b, int size_a);
int		insert(t_list **stack_a, t_list **stack_b, int size_a);
void	sort(t_list **stack_a, t_list **stack_b, int n);

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = parse_input(argc, argv);
	stack_b = ft_calloc(1, sizeof(t_list *));
	if (minichecker(stack_a, stack_b))
		exit_gracefully(stack_a, NULL, NULL, EXIT_SUCCESS);
	init(stack_a, stack_b);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(stack_a, NULL, NULL, EXIT_SUCCESS);
	sort(stack_a, stack_b, 3);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(stack_a, NULL, NULL, EXIT_SUCCESS);
	goto_val(stack_a, 'a', ft_lstmin(stack_a, INT));
	exit_gracefully(stack_a, stack_b, NULL, EXIT_SUCCESS);
	return (1);
}

void	init(t_list **stack_a, t_list **stack_b)
{
	size_t	i;
	size_t	len;
	int		int1;
	int		int2;
	int		int3;

	len = ft_lstsize(*stack_a);
	i = 0;
	while (i + 2 < len)
	{
		int1 = *(int *)(*stack_a)->content;
		int2 = *(int *)(*stack_a)->next->content;
		int3 = *(int *)(*stack_a)->next->next->content;
		if (int1 < int2 && int1 < int3)
		{
			ra(stack_a);
			if (int2 > int3)
				sa(stack_a);
			rotate_i(stack_a, 2, 'a');
		}
		else if (int2 < int1 && int2 < int3)
		{
			sa(stack_a);
			ra(stack_a);
			if (int1 > int3)
				sa(stack_a);
			rotate_i(stack_a, 2, 'a');
		}
		else if (int3 < int1 && int3 < int2)
		{
			pb(stack_a, stack_b);
			sa(stack_a);
			ra(stack_a);
			pa(stack_a, stack_b);
			if (int1 > int2)
				sa(stack_a);
			rotate_i(stack_a, 2, 'a');
		}
		i += 3;
	}
	rotate_i(stack_a, len % 3, 'a');
	return ;
}

void	merge(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	i;

	i = 0;
	size_a += ft_lstsize(*stack_b);
	while (*stack_b)
	{
		rrb(stack_b);
		i += insert(stack_a, stack_b, size_a);
	}
	rotate_i(stack_a, size_a - i, 'a');
	return ;
}

int	insert(t_list **stack_a, t_list **stack_b, int size_a)
{
	int		stb;
	int		i;

	i = 0;
	stb = *(int *)(*stack_b)->content;
	if (stb < *(int *)(*stack_a)->content)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		return (1);
	}
	while (stb > *(int *)(*stack_a)->content && i < size_a - 1)
	{
		ra(stack_a);
		i++;
	}
	pa(stack_a, stack_b);
	ra(stack_a);
	return (i + 1);
}

void	sort(t_list **stack_a, t_list **stack_b, int n)
{
	int	lenleft;

	while (n < ft_lstsize(*stack_a))
	{
		lenleft = ft_lstsize(*stack_a);
		while (lenleft > n)
		{
			push_bloc(stack_a, stack_b, n, 1);
			merge(stack_a, stack_b, (int)ft_min(lenleft - n, n));
			lenleft -= (int)ft_min(lenleft, 2 * n);
		}
		rotate_i(stack_a, lenleft, 'a');
		n *= 2;
		if (minichecker(stack_a, stack_b))
			exit_gracefully(stack_a, stack_b, NULL, EXIT_SUCCESS);
	}
	return ;
}
