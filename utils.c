/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:50:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/12 22:20:02 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	goto_val(t_list **stack, char ab, int value);
t_list	**parse_input(int argc, char *argv[]);
void	exit_gracefully(t_list **stack_a, t_list **stack_b, int status);
void	add_to_stack(t_list **stack, char *str);
int		get_n(t_list **stack, int n);

void	goto_val(t_list **stack, char ab, int value)
{
	t_list	*current;
	size_t	i_rot;

	if (!stack || !*stack)
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
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
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
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
	if (!*arguments)
		exit_gracefully(stack_a, NULL, EXIT_FAILURE);
	while (arguments[i])
	{
		add_to_stack(stack_a, arguments[i]);
		i++;
	}
	return (stack_a);
}

void	exit_gracefully(t_list **stack_a, t_list **stack_b, int status)
{
	static t_list	**stack_1 = NULL;
	static t_list	**stack_2 = NULL;

	if (stack_a)
		stack_1 = stack_a;
	if (stack_b)
		stack_2 = stack_b;
	if (status == EXIT_FAILURE)
		write(2, "Error\n", 6);
	else if (status == EXIT_SUCCESS)
		add_instr(NULL, true);
	else if (status == -1)
		return ;
	print_list(stack_a, stack_b);
	if (stack_1)
		ft_lstclear(stack_1, free);
	if (stack_2)
		ft_lstclear(stack_2, free);
	add_instr(NULL, false);
	exit(status);
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
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		tmp = ft_calloc(1, sizeof(int));
		if (!tmp)
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		*tmp = ft_atoi(str);
		if (ft_lst_isin(stack, tmp, sizeof(int)))
		{
			free(tmp);
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		}
		new_node = ft_lstnew(tmp);
		if (!new_node)
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		ft_lstadd_back(stack, new_node);
	}
}

int	get_n(t_list **stack, int n)
{
	if (ft_lst_getn(stack, n))
		return (*(int *)((ft_lst_getn(stack, n))->content));
	else
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return (0);
}
