/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 19:56:32 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	init(t_list **stack_a, t_list **stack_b);
void	merge(t_list **stack_a, t_list **stack_b);
void	insert(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b, size_t n);

int		minichecker(t_list **stack_a, t_list **stack_b);

int	main(int argc, char *argv[])
{
	int		i;
	t_list	**stack_a;
	t_list	**stack_b;
	int		*tmp;
	t_list	*new_node;

	i = 1;
	stack_a = ft_calloc(1, sizeof(t_list *));
	stack_b = ft_calloc(1, sizeof(t_list *));
	while (i < argc)
	{
		tmp = ft_calloc(1, sizeof(int));
		*tmp = ft_atoi(argv[i]);
		new_node = ft_lstnew(tmp);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	init(stack_a, stack_b);
	sort(stack_a, stack_b, 4);
	reset_a(stack_a);
	return (1);
}

void	init(t_list **stack_a, t_list **stack_b)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_lstsize(*stack_a);
	while (i < len)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
		push_bloc(stack_a, stack_b, 2, 1);
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
		merge(stack_a, stack_b);
		push_bloc(stack_a, stack_b, 4, -1);
		rotate_i(stack_a, 4);
		i += 4;
	}
	return ;
}

void	merge(t_list **stack_a, t_list **stack_b)
{
	size_t	len;
	size_t	i;

	len = (size_t)ft_lstsize(*stack_b);
	if (len > (size_t)ft_lstsize(*stack_a))
		len = (size_t)ft_lstsize(*stack_a);
	i = 0;
	while (i < len)
	{
		insert(stack_a, stack_b);
		i++;
	}
	return ;
}

void	insert(t_list **stack_a, t_list **stack_b)
{
	int	sta;

	sta = *(int *)(*stack_a)->content;
	if (sta <= get_min(stack_b))
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		return ;
	}
	else if (sta >= get_max(stack_b))
	{
		reset_b(stack_b);
		pb(stack_a, stack_b);
		return ;
	}
	while (!((*(int *)(*stack_b)->content) <= sta
		&& (sta <= *(int *)ft_lstlast(*stack_b)->content)))
		rb(stack_b);
	pb(stack_a, stack_b);
	return ;
}

void	sort(t_list **stack_a, t_list **stack_b, size_t n)
{
	if ((int)n > ft_lstsize(*stack_a))
		return ;
	push_bloc(stack_a, stack_b, n, 1);
	merge(stack_a, stack_b);
	reset_b(stack_b);
	push_bloc(stack_a, stack_b, 2 * n, -1);
	return (sort(stack_a, stack_b, 2 * n));
}
