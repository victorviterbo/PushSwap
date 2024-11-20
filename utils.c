/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:50:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/20 17:34:07 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		goto_val(t_list **stack, char ab, int value, bool dummy);
t_list	**parse_input(int argc, char *argv[]);
void	exit_gracefully(t_list **stack_a, t_list **stack_b, int status);
void	add_to_stack(t_list **stack, char *str);
int		get_n(t_list **stack, int n);

int	goto_val(t_list **stack, char ab, int value, bool dummy)
{
	int		i_rot;
	t_list	*c;

	if (!stack || !*stack)
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	i_rot = 0;
	c = *stack;
	if (value > ft_lstmaxi(stack) || value < ft_lstmini(stack))
		value = ft_lstmini(stack);
	i_rot = 1;
	if (c->i > value && ft_lstlast(*stack)->i < value)
		return (0);
	while (c->next && (c->i > value || c->next->i < value) && c->i != value)
	{
		i_rot++;
		c = c->next;
	}
	i_rot = i_rot - (c->i == value);
	if (dummy == false)
		rotate_i(stack, NULL, i_rot, ab);
	return (i_rot);
}

t_list	**parse_input(int argc, char *argv[])
{
	size_t	i;
	t_list	**stack_a;
	char	**arguments;

	i = -1;
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
		i = 0;
	}
	if (!*arguments)
	{
		free(arguments);
		exit_gracefully(stack_a, NULL, EXIT_FAILURE);
	}
	while (arguments[++i])
		add_to_stack(stack_a, arguments[i]);
	return (ft_free_array((void **)arguments, ft_arrlen(arguments)), stack_a);
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
	if (stack_1)
	{
		ft_lstclear(stack_1, ft_dummy);
		free(stack_1);
	}
	if (stack_2)
	{
		ft_lstclear(stack_2, ft_dummy);
		free(stack_2);
	}
	add_instr(NULL, false);
	exit(status);
}

void	add_to_stack(t_list **stack, char *str)
{
	t_list	*new_node;
	char	**splitted;

	if (ft_strchr(str, ' '))
	{
		splitted = ft_split(str, ' ');
		while (splitted && *(splitted))
		{
			add_to_stack(stack, *(splitted));
			free(*(splitted));
			splitted++;
		}
	}
	else
	{
		if (!ft_isnumber(str))
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		if (ft_lst_isin_int(stack, ft_atoi(str)))
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		new_node = ft_lstnew_int(ft_atoi(str));
		if (!new_node)
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		ft_lstadd_back(stack, new_node);
	}
}

int	get_n(t_list **stack, int n)
{
	if (ft_lst_getn(stack, n))
		return (((ft_lst_getn(stack, n))->i));
	else
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return (0);
}
