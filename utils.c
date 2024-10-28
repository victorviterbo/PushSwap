/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:50:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 20:59:10 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		get_min(t_list **stack_a);
int		get_max(t_list **stack_a);
char	*reset_a(t_list **stack_a);
char	*reset_b(t_list **stack_b);
t_list	**parse_input(int argc, char *argv[]);

int	get_min(t_list **stack_a)
{
	int		min;
	t_list	*current;

	min = INT_MAX;
	current = *stack_a;
	while (current)
	{
		if (*(int *)current->content < min)
			min = *(int *)current->content;
		current = current->next;
	}
	return (min);
}

int	get_max(t_list **stack_a)
{
	int		max;
	t_list	*current;

	max = INT_MIN;
	current = *stack_a;
	while (current)
	{
		if (*(int *)current->content > max)
			max = *(int *)current->content;
		current = current->next;
	}
	return (max);
}

char	*reset_a(t_list **stack_a)
{
	char	*ret;

	ret = ft_calloc(1, 1);
	while (*(int *)(*stack_a)->content != get_min(stack_a))
		ret = ft_strjoin_ip(ret, ra(stack_a), 1);
	return (ret);
}

char	*reset_b(t_list **stack_b)
{
	char	*ret;

	ret = ft_calloc(1, 1);
	while (*(int *)(*stack_b)->content != get_max(stack_b))
		ret = ft_strjoin_ip(ret, rb(stack_b), 1);
	return (ret);
}

t_list	**parse_input(int argc, char *argv[])
{
	int		i;
	int		*tmp;
	t_list	*new_node;
	t_list	**stack_a;

	i = 1;
	stack_a = ft_calloc(1, sizeof(t_list *));

	while (i < argc)
	{
		tmp = ft_calloc(1, sizeof(int));
		*tmp = ft_atoi(argv[i]);
		new_node = ft_lstnew(tmp);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	return (stack_a);
}
