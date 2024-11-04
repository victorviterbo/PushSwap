/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:24:19 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/04 14:52:25 by vviterbo         ###   ########.fr       */
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
	while (1)
	{
		operation = get_next_line(0);
		if (operation)
			do_operation(stack_a, stack_b, operation, ft_strlen(operation));
		else
			exit_gracefully(stack_a, stack_b, NULL, EXIT_FAILURE);
		free(operation);
	}
	if (minichecker(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	minichecker(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		last;

	if ((*stack_b))
		return (0);
	last = *(int *)(*stack_a)->content;
	current = (*stack_a)->next;
	while (current)
	{
		if (*(int *)current->content < last)
			return (0);
		last = *(int *)current->content;
		current = current->next;
	}
	return (1);
}

int	do_operation(t_list **stack_a, t_list **stack_b, char *op, int len)
{
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
	if (!ft_memcmp(op, "rra\n", len))
		return (rra(stack_a), 0);
	if (!ft_memcmp(op, "rrb\n", len))
		return (rrb(stack_b), 0);
	if (!ft_memcmp(op, "rrr\n", len))
		return (rrr(stack_a, stack_b), 0);
	if (!ft_memcmp(op, "pa\n", len))
		return (pa(stack_a, stack_b), 0);
	if (!ft_memcmp(op, "pb\n", len))
		return (pb(stack_a, stack_b), 0);
	else
		exit_gracefully(stack_a, stack_b, op, EXIT_FAILURE);
	return (1);
}
