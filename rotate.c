/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:58:46 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 20:59:24 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	rotate(t_list **stack);
char	*ra(t_list **stack_a);
char	*rb(t_list **stack_b);
char	*rr(t_list **stack_a, t_list **stack_b);
char	*rotate_i(t_list **stack_a, size_t n);

void	rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstlast(*stack)->next = tmp;
	tmp->next = NULL;
	return ;
}

char	*ra(t_list **stack_a)
{
	rotate(stack_a);
	return ("ra\n");
}

char	*rb(t_list **stack_b)
{
	rotate(stack_b);
	return ("rb\n");
}

char	*rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	return ("rr\n");
}

char	*rotate_i(t_list **stack_a, size_t n)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = ft_calloc(1, 1);
	while (i < n)
	{
		ret = ft_strjoin_ip(ret, ra(stack_a), 1);
		i++;
	}
	return (ret);
}
