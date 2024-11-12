/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:19:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/12 19:30:53 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	add_instr(char *str, bool print);
t_list	**simplify(t_list **out, int last_size);
void	write_output(t_list **stack);
int		is_simplifiable(char *str1, char *str2);
int		minichecker(t_list **stack_a, t_list **stack_b);

void	add_instr(char *str, bool print)
{
	static t_list	**output = NULL;
	t_list			*new_instr;

	if (print && output)
		write_output(output);
	else if (!str)
		ft_lstclear(output, free);
	else if (!output && str && *str)
	{
		output = ft_calloc(1, sizeof(t_list *));
		if (!output)
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		*output = ft_lstnew(ft_strdup((void *)str));
	}
	else if (str && *str)
	{
		new_instr = ft_lstnew(ft_strdup((void *)str));
		if (!new_instr || !new_instr->content)
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		ft_lstadd_back(output, new_instr);
	}
	else
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return ;
}

void	write_output(t_list **out)
{
	t_list	*current;
	char	*instruction;

	simplify(out, ft_lstsize(*out) + 1);
	current = *out;
	while (current)
	{
		instruction = (char *)current->content;
		write(1, instruction, ft_strlen(instruction));
		current = current->next;
	}
	ft_lstclear(out, free);
	return ;
}

t_list	**simplify(t_list **out, int last_size)
{
	t_list	*current;
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	if (last_size == ft_lstsize(*out))
		return (out);
	last_size = ft_lstsize(*out);
	current = *out;
	while (current->next)
	{
		str1 = (char *)current->content;
		str2 = (char *)current->next->content;
		j = is_simplifiable(str1, str2);
		if (j >= 0)
		{
			ft_lstcut(out, free, i, i + j);
			return (simplify(out, last_size));
		}
		i++;
		current = current->next;
	}
	return (out);
}

int	is_simplifiable(char *str1, char *str2)
{
	if ((*str1 == 'p' && *str2 == 'p')
		&& (*(str1 + 1) != *(str2 + 1)))
		return (2);
	if ((*(str1) == 's' && *(str2) == 's')
		&& (*(str1 + 1) == *(str2 + 1)))
		return (2);
	if ((*(str1) == 'r' && *(str2) == 'r')
		&& ((*(str1 + 1) == 'r' && *(str2 + 1) != 'r')
			|| (*(str1 + 1) != 'r' && *(str2 + 1) == 'r'))
		&& (*(str1 + ft_strlen(str1) - 2) == *(str2 + ft_strlen(str2) - 2)))
		return (2);
	return (-1);
}

int	minichecker(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		last;

	if (stack_b && (*stack_b))
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
