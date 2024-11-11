/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:50:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/11 13:10:48 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	goto_val(t_list **stack, char ab, int value);
t_list	**parse_input(int argc, char *argv[]);
void	add_to_stack(t_list **stack, char *str);
void	exit_gracefully(t_list **stack_a, t_list **stack_b,
			char *str, int status);
int		minichecker(t_list **stack_a, t_list **stack_b);

void	goto_val(t_list **stack, char ab, int value)
{
	t_list	*current;
	size_t	i_rot;

	if (!stack || !*stack)
		exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
	current = *stack;
	i_rot = 0;
	while (current->next && *(int *)current->content != value
		&& !(*(int *)current->content > value
			&& *(int *)current->next->content < value))
	{
		current = current->next;
		i_rot++;
	}
	i_rot += (int)(*(int *)current->content != value);
	if (current)
		rotate_i(stack, i_rot, ab);
	return ;
}

t_list	**parse_input(int argc, char *argv[])
{
	size_t	i;
	t_list	**stack_a;
	char	**arguments;

	i = 0;
	if (argc < 2)
		exit_gracefully(NULL, NULL, NULL, EXIT_FAILURE);
	stack_a = ft_calloc(1, sizeof(t_list *));
	if (!stack_a)
		return (NULL);
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
	{
		arguments = ft_strarray_mapi(argv, ft_strdup);
		i = 1;
	}
	while (arguments[i])
	{
		add_to_stack(stack_a, arguments[i]);
		i++;
	}
	return (stack_a);
}

void	add_to_stack(t_list **stack, char *str)
{
	int		*tmp;
	t_list	*new_node;

	if (ft_strchr(str, ' '))
		add_to_stack(stack, str);
	else
	{
		if (!ft_isnumber(str))
			exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
		tmp = ft_calloc(1, sizeof(int));
		if (!tmp)
			exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
		*tmp = ft_atoi(str);
		if (ft_lst_isin(stack, tmp, sizeof(int)))
		{
			free(tmp);
			exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
		}
		new_node = ft_lstnew(tmp);
		if (!new_node)
			exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
		ft_lstadd_back(stack, new_node);
	}
}

void	exit_gracefully(t_list **stack_a, t_list **stack_b,
			char *str, int status)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	if (str)
		free(str);
	if (status == EXIT_FAILURE)
		write(1, "Error\n", 6);
	else
		add_instr("", true);
	exit(status);
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
