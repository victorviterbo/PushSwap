/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:45:15 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 20:14:11 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	push(t_list **stack_a, t_list **stack_b);
char	*pa(t_list **stack_a, t_list **stack_b);
char	*pb(t_list **stack_a, t_list **stack_b);
char	*push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir);

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*next_node_a;
	t_list	*next_node_b;

	if (!*stack_b)
		return ;
	if (!*stack_a)
		next_node_a = NULL;
	else
		next_node_a = *stack_a;
	*stack_a = *stack_b;
	next_node_b = (*stack_b)->next;
	(*stack_a)->next = next_node_a;
	*stack_b = next_node_b;
	return ;
}

char	*pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	return ("pa\n");
}

char	*pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	return ("pb\n");
}

char	*push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = ft_calloc(1, 1);
	while (i < size)
	{
		if (dir == 1)
			ret = ft_strjoin_ip(ret, pb(stack_a, stack_b), 1);
		else if (dir == -1)
			ret = ft_strjoin_ip(ret, pa(stack_a, stack_b), 1);
		i++;
	}
	return (ret);
}
