/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:19:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/20 17:24:24 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_instr(const char *str, bool print);
void	write_output(t_list **stack);
int		minichecker(t_list **stack_a, t_list **stack_b);

void	add_instr(const char *str, bool print)
{
	static t_list	**output = NULL;
	t_list			*new_instr;

	if (print && output && !str)
		write_output(output);
	else if (!(str))
		ft_lstclear(output, free);
	else if (!output && str && *str)
	{
		output = ft_calloc(1, sizeof(t_list *));
		if (!output)
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
		*output = ft_lstnew_void(ft_strdup((void *)str));
	}
	else if (str && *str)
	{
		new_instr = ft_lstnew_void(ft_strdup((void *)str));
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

int	minichecker(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		last;

	if (stack_b && (*stack_b))
		return (0);
	last = (*stack_a)->i;
	current = (*stack_a)->next;
	while (current)
	{
		if (current->i < last)
			return (0);
		last = current->i;
		current = current->next;
	}
	return (1);
}
