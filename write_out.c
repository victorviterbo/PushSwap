/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:19:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/10 17:30:01 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	add_instr(char *str, bool print);
t_list	**simplify(t_list **out, int last_size);
t_list	**cut(t_list **out, int start, int end);
void	write_output(t_list **stack);

void	add_instr(char *str, bool print)
{
	static t_list	**output = NULL;
	t_list			*new_instr;

	if (print)
	{
		output = simplify(output, ft_lstsize(*output) + 1);
		write_output(output);
	}
	if (!output && str)
	{
		output = ft_calloc(1, sizeof(t_list *));
		*output = ft_lstnew((void *)str);
		if (!output)
			exit_gracefully(NULL, NULL, NULL, EXIT_FAILURE);
	}
	else if (str)
	{
		new_instr = ft_lstnew((void *)str);
		if (!new_instr)
			exit_gracefully(output, NULL, NULL, EXIT_SUCCESS);
		ft_lstadd_back(output, new_instr);
	}
	else
		exit_gracefully(output, NULL, NULL, EXIT_FAILURE);
	return ;
}

t_list	**simplify(t_list **out, int last_size)
{
	t_list	*current;
	int		i;
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
		if ((*str1 == 'p' && *str2 == 'p')
			&& (*(str1 + 1) != *(str2 + 1)))
			return (simplify(cut(out, i, i + 2), last_size));
		if ((*(str1) == 's' && *(str2) == 's')
			&& (*(str1 + 1) == *(str2 + 1)))
			return (simplify(cut(out, i, i + 2), last_size));
		if ((*(str1) == 'r' && *(str2) == 'r')
			&& ((*(str1 + 1) == 'r' && *(str2 + 1) != 'r')
				|| (*(str1 + 1) != 'r' && *(str2 + 1) == 'r'))
			&& (*(str1 + ft_strlen(str1) - 2) == *(str2 + ft_strlen(str2) - 2)))
			return (simplify(cut(out, i, i + 2), last_size));
		i++;
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
		if (start <= i && i < end)
			ft_lstdelone(current, free);
		else if (i == end && start)
			last->next = current;
		else if (i == end)
			*out = current;
		else
			last = current;
		current = next;
		i++;
	}
	return out;
}

void	write_output(t_list **out)
{
	t_list	*current;

	current = *out;
	while (current)
	{
		
	}
}