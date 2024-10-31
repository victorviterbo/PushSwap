/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:50:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/31 21:07:52 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		get_min(t_list **stack_a);
int		get_max(t_list **stack_a);
char	*reset(t_list **stack, char ab);
t_list	**parse_input(int argc, char *argv[]);
void	*free_stack(t_list **stack);

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

char	*reset(t_list **stack, char ab)
{
	char	*ret;
	int		target;

	ret = ft_calloc(1, 1);
	if (!ret)
		return (NULL);
	if (ab == 'a')
		target = get_min(stack);
	else
		target = get_max(stack);
	while (*(int *)(*stack)->content != target)
	{
		if (ab == 'a')
			ret = ft_strjoin_ip(ret, ra(stack), 1);
		else
			ret = ft_strjoin_ip(ret, rb(stack), 1);
	}
	return (ret);
}

t_list	**parse_input(int argc, char *argv[])
{
	size_t	i;
	int		*tmp;
	t_list	*new_node;
	t_list	**stack_a;

	i = 0;
	stack_a = ft_calloc(1, sizeof(t_list *));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (free_stack(stack_a));
		tmp = ft_calloc(1, sizeof(int));
		*tmp = ft_atoi(argv[i]);
		new_node = ft_lstnew(tmp);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	return (stack_a);
}

void	*free_stack(t_list **stack)
{
	t_list	*node;
	t_list	*next_node;

	node = *stack;
	while (node)
	{
		next_node = node->next;
		free(node->content);
		free(node);
		node = next_node;
	}
	return (NULL);
}
