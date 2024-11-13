/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/13 08:58:40 by vviterbo         ###   ########.fr       */
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
	exit_gracefully(stack_a, stack_b, -1);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	if (ft_lstsize(*stack_a) <= 5)
		minisort(stack_a, stack_b);
	print_list(stack_a, stack_b);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	radix_sort(stack_a, stack_b);
	printf("radix sort failed\n");
	print_list(stack_a, stack_b);
	init(stack_a, stack_b);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	sort(stack_a, stack_b, 5);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return (1);
}

void	init(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	len;

	len = ft_lstsize(*stack_a);
	i = 0;
	while (i + 1 < len)
	{
		usort(stack_a, stack_b, ft_min(5, len - i));
		i += 5;
	}
	if (len % 5 == 1)
		ra(stack_a);
	return ;
}

void	merge(t_list **stack_a, t_list **stack_b, int size_a)
{
	while (*stack_b)
	{
		if (ft_lstsize(*stack_b) > 1)
			rrb(stack_b);
		size_a -= insert(stack_a, stack_b, size_a);
	}
	rotate_i(stack_a, size_a, 'a');
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
		return (0);
	}
	while (stb > *(int *)(*stack_a)->content && i < size_a)
	{
		ra(stack_a);
		i++;
	}
	pa(stack_a, stack_b);
	ra(stack_a);
	return (i);
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
			if (minichecker(stack_a, stack_b))
				exit_gracefully(NULL, NULL, EXIT_SUCCESS);
		}
		rotate_i(stack_a, lenleft, 'a');
		n *= 2;
	}
	return ;
}
