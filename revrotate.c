/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:58:46 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 20:59:42 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	revrotate(t_list **stack);
char	*rra(t_list **stack_a);
char	*rrb(t_list **stack_b);
char	*rrr(t_list **stack_a, t_list **stack_b);

void	revrotate(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	ft_lstlast(*stack)->next = *stack;
	(*stack)->next = NULL;
	(*stack) = tmp;
	return ;
}

char	*rra(t_list **stack_a)
{
	revrotate(stack_a);
	return ("rra\n");
}

char	*rrb(t_list **stack_b)
{
	revrotate(stack_b);
	return ("rrb\n");
}

char	*rrr(t_list **stack_a, t_list **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	return ("rrr\n");
}
