/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:24:19 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/03 16:23:32 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int	main(int argc, char *argv[]);
int	minichecker(t_list **stack_a, t_list **stack_b);

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*operation;

	stack_a = parse_input(argc, argv);
	stack_b = ft_calloc(1, sizeof(t_list *));
	// INCLUDE GNL FOR OUTPUT PARSING
	while (1)
	{
		operation = get_next_line(0);
		if (operation)
			do_operation(stack_a, stack_b, operation);
		else
			break ;
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