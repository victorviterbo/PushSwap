/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:19:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/11 17:15:12 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	add_instr(char *str, bool print);
t_list	**simplify(t_list **out, int last_size);
t_list	**cut(t_list **out, int start, int end);
void	write_output(t_list **stack);
int		is_simplifiable(char *str1, char *str2);

void	add_instr(char *str, bool print)
{
	static t_list	**output = NULL;
	t_list			*new_instr;

	if (print)
		write_output(output);
	else if (!str)
		ft_lstclear(output, free);
	else if (!output && str && *str)
	{
		output = ft_calloc(1, sizeof(t_list *));
		*output = ft_lstnew(ft_strdup((void *)str));
		if (!output)
			exit_gracefully(NULL, NULL, EXIT_FAILURE);
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
			return (simplify(cut(out, i, i + j), last_size));
		i++;
		current = current->next;
	}
	return (out);
}

t_list	**cut(t_list **out, int start, int end)
{
	t_list	*current;
	t_list	*last;
	t_list	*next;
	int		i;

	i = 0;
	current = *out;
	while (current)
	{
		next = current->next;
		if (i < start)
			last = current;
		else if (start <= i && i < end)
			ft_lstdelone(current, free);
		else if (i == end && start)
			last->next = current;
		else if (i == end)
			*out = current;
		current = next;
		i++;
	}
	if (i <= end)
		last->next = NULL;
	return (out);
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
