/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:50:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/03 16:55:18 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		get_min(t_list **stack_a);
int		get_max(t_list **stack_a);
char	*reset(t_list **stack, char ab);
t_list	**parse_input(int argc, char *argv[]);
void	cleanUp(void);

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
	t_list	**stack_a;

	i = 0;
	stack_a = ft_calloc(1, sizeof(t_list *));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		add_to_stack(stack_a, argv[i]);
		i++;
	}
	return (stack_a);
}

void	add_to_stack(t_list **stack, char *str)
{
	size_t	i;
	int		*tmp;
	char	**splitted;
	t_list	*new_node;

	i = 0;
	splitted = ft_split(str, ' ');
	while (*(splitted + i))
	{
		if (ft_strchr(*(splitted + i), ' '))
			add_to_stack(stack, *(splitted + i));
		else
		{
			if (!ft_isnumber(*(splitted + i)))
				exit_gracefully(stack, 1);
			tmp = ft_calloc(1, sizeof(int));
			if (!tmp)
				exit_gracefully(stack, 0);
			*tmp = ft_atoi(*(splitted + i));
			new_node = ft_lstnew(tmp);
			ft_lstadd_back(stack, new_node);
		}
		i++;
	}
}
