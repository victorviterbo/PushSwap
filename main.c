/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 19:01:54 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	init(t_list **stack_a, t_list **stack_b);
void	push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir);
void	merge(t_list **stack_a, t_list **stack_b);
void	insert(t_list **stack_a, t_list **stack_b);
void	rotate_i(t_list **stack_a, size_t n);
void	sort(t_list **stack_a, t_list **stack_b, size_t n);
int		get_min(t_list **stack_a);
int		get_max(t_list **stack_a);
void	reset_a(t_list **stack_a);
void	reset_b(t_list **stack_b);
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
	//print_list(stack_a, stack_b);
	init(stack_a, stack_b);
	sort(stack_a, stack_b, 4);
	reset_a(stack_a);
	/*
	if (minichecker(stack_a, stack_b))
		printf(">>>>>> SUCCESS <<<<<<\n");
	else
	{
		printf(">>>>>> FAILURE <<<<<<\n");
		print_list(stack_a, stack_b);
	}
	*/
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

void	push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (dir == 1)
			pb(stack_a, stack_b);
		else if (dir == -1)
			pa(stack_a, stack_b);
		i++;
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
	if (*(int *)(*stack_a)->content <= get_min(stack_b))
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		return ;
	}
	else if (*(int *)(*stack_a)->content >= get_max(stack_b))
	{
		reset_b(stack_b);
		pb(stack_a, stack_b);
		return ;
	}
	while (!((*(int *)(*stack_b)->content) <= *(int *)(*stack_a)->content && (*(int *)(*stack_a)->content <= *(int *)ft_lstlast(*stack_b)->content)))
		rb(stack_b);
	pb(stack_a, stack_b);
	return ;
}

void	rotate_i(t_list **stack_a, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		ra(stack_a);
		i++;
	}
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

void	reset_a(t_list **stack_a)
{
	while (*(int *)(*stack_a)->content != get_min(stack_a))
		ra(stack_a);
	return;
}

void	reset_b(t_list **stack_b)
{
	while (*(int *)(*stack_b)->content != get_max(stack_b))
		rb(stack_b);
	return;
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
