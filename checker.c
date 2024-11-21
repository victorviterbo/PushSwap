/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:24:19 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/21 21:48:35 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[]);
int	minichecker(t_list **stack_a, t_list **stack_b);
int	do_operation(t_list **stack_a, t_list **stack_b, char *op, int len);

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*operation;

	stack_a = parse_input(argc, argv);
	stack_b = ft_calloc(1, sizeof(t_list *));
	exit_gracefully(stack_a, stack_b, INIT_PTR);
	while (1)
	{
		operation = ft_get_next_line(0);
		if (operation)
			do_operation(stack_a, stack_b, operation, ft_strlen(operation));
		else
			break ;
		free(operation);
	}
	if (minichecker(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit_gracefully(NULL, NULL, EXIT_SILENTLY);
	return (0);
}

int	do_operation(t_list **stack_a, t_list **stack_b, char *op, int len)
{
	if (!ft_memcmp(op, "rra\n", len))
		return (rra(stack_a), 0);
	if (!ft_memcmp(op, "rrb\n", len))
		return (rrb(stack_b), 0);
	if (!ft_memcmp(op, "rrr\n", len))
		return (rrr(stack_a, stack_b), 0);
	if (!ft_memcmp(op, "sa\n", len))
		return (sa(stack_a), 0);
	if (!ft_memcmp(op, "sb\n", len))
		return (sb(stack_b), 0);
	if (!ft_memcmp(op, "ss\n", len))
		return (ss(stack_a, stack_b), 0);
	if (!ft_memcmp(op, "ra\n", len))
		return (ra(stack_a), 0);
	if (!ft_memcmp(op, "rb\n", len))
		return (rb(stack_b), 0);
	if (!ft_memcmp(op, "rr\n", len))
		return (rr(stack_a, stack_b), 0);
	if (!ft_memcmp(op, "pa\n", len))
		return (pa(stack_a, stack_b), 0);
	if (!ft_memcmp(op, "pb\n", len))
		return (pb(stack_a, stack_b), 0);
	else
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return (1);
}
