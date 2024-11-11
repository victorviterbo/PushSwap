/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/11 16:57:10 by vviterbo         ###   ########.fr       */
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
	printf("1\n");
	print_list(stack_a, stack_b);
	exit_gracefully(stack_a, stack_b, -1);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	printf("2\n");
	print_list(stack_a, stack_b);
	init(stack_a, stack_b);
	printf("3\n");
	print_list(stack_a, stack_b);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	printf("3.5\n");
	print_list(stack_a, stack_b);
	sort(stack_a, stack_b, 5);
	printf("4\n");
	print_list(stack_a, stack_b);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	return (1);
}

void	init(t_list **stack_a, t_list **stack_b)
{
	size_t	i;
	size_t	len;

	len = ft_lstsize(*stack_a);
	i = 0;
	while (i + 1 < len)
	{
		usort(stack_a, stack_b, ft_min(5, len - i));
		i += 5;
	}
	rotate_i(stack_a, ft_max(0, len - i), 'a');
	return ;
}

void	merge(t_list **stack_a, t_list **stack_b, int size_a)
{
	while (*stack_b)
	{
		rrb(stack_b);
		size_a -= insert(stack_a, stack_b, size_a);
	}
	printf("STACK B SHOULD BE EMPTY\n");
	print_list(stack_a, stack_b);
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
