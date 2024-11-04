/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/04 14:28:59 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		main(int argc, char *argv[]);
void	init(t_list **stack_a);
void	merge(t_list **stack_a, t_list **stack_b, size_t size_a);
void	insert(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b, size_t n);

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*instructions;

	instructions = ft_calloc(1, 1);
	stack_a = parse_input(argc, argv);
	stack_b = ft_calloc(1, sizeof(t_list *));
	init(stack_a);
	sort(stack_a, stack_b, 2);
	reset(stack_a, 'a');
	write(1, instructions, ft_strlen(instructions));
	return (ft_lstclear(stack_a, free), ft_lstclear(stack_b, free), 1);
}

void	init(t_list **stack_a)
{
	size_t	i;
	size_t	len;

	len = ft_lstsize(*stack_a);
	i = len % 2;
	while (i < len)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
		rotate_i(stack_a, 2);
		i += 2;
	}
	rotate_i(stack_a, len % 2);
	return ;
}

void	merge(t_list **stack_a, t_list **stack_b, size_t size_a)
{
	size_t	i;

	i = 0;
	while (i < size_a)
	{
		insert(stack_a, stack_b);
		i++;
	}
	reset(stack_b, 'b');
	return ;
}

void	insert(t_list **stack_a, t_list **stack_b)
{
	int		sta;

	sta = *(int *)(*stack_a)->content;
	if (sta <= get_min(stack_b))
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		return ;
	}
	else if (sta >= get_max(stack_b))
	{
		reset(stack_b, 'b');
		pb(stack_a, stack_b);
		return ;
	}
	while (!((*(int *)(*stack_b)->content) <= sta
		&& (sta <= *(int *)ft_lstlast(*stack_b)->content)))
		rrb(stack_b);
	pb(stack_a, stack_b);
	return ;
}

void	sort(t_list **stack_a, t_list **stack_b, size_t n)
{
	size_t	lenleft;
	size_t	sorted;

	while (n <= (size_t)ft_lstsize(*stack_a))
	{
		lenleft = (size_t)ft_lstsize(*stack_a);
		while (lenleft >= n)
		{
			push_bloc(stack_a, stack_b, n, 1);
			merge(stack_a, stack_b, ft_min(lenleft - n, n));
			reset(stack_b, 'b');
			sorted = ft_lstsize(*stack_b);
			push_bloc(stack_a, stack_b, sorted, -1);
			rotate_i(stack_a, sorted);
			lenleft -= sorted;
		}
		rotate_i(stack_a, lenleft);
		n *= 2;
	}
	return ;
}
