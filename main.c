/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/04 13:46:56 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		main(int argc, char *argv[]);
char	*init(t_list **stack_a);
char	*merge(t_list **stack_a, t_list **stack_b, size_t size_a);
char	*insert(t_list **stack_a, t_list **stack_b);
char	*sort(t_list **stack_a, t_list **stack_b, size_t n);

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*instructions;

	instructions = ft_calloc(1, 1);
	stack_a = parse_input(argc, argv);
	stack_b = ft_calloc(1, sizeof(t_list *));
	instructions = ft_strjoin_ip(instructions, init(stack_a), 1);
	instructions = ft_strjoin_ip(instructions, sort(stack_a, stack_b, 2), 1);
	instructions = ft_strjoin_ip(instructions, reset(stack_a, 'a'), 1);
	instructions = simplify(instructions, ft_strlen(instructions) + 1);
	write(1, instructions, ft_strlen(instructions));
	return (ft_lstclear(stack_a, free), ft_lstclear(stack_b, free),
		free(instructions), 1);
}

char	*init(t_list **stack_a)
{
	size_t	i;
	size_t	len;
	char	*ret;

	ret = ft_calloc(1, 1);
	if (!ret)
		return (NULL);
	len = ft_lstsize(*stack_a);
	i = len % 2;
	while (i < len)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			ret = ft_strjoin_ip(ret, sa(stack_a), 1);
		ret = ft_strjoin_ip(ret, rotate_i(stack_a, 2), 1);
		i += 2;
	}
	ret = ft_strjoin_ip(ret, rotate_i(stack_a, len % 2), 1);
	return (ret);
}

char	*merge(t_list **stack_a, t_list **stack_b, size_t size_a)
{
	size_t	i;
	char	*ret;

	ret = ft_calloc(1, 1);
	i = 0;
	while (i < size_a)
	{
		ret = ft_strjoin_ip(ret, insert(stack_a, stack_b), 1);
		i++;
	}
	ret = ft_strjoin_ip(ret, reset(stack_b, 'b'), 1);
	return (ret);
}

char	*insert(t_list **stack_a, t_list **stack_b)
{
	int		sta;
	char	*ret;

	ret = ft_calloc(1, 1);
	if (!ret)
		return (NULL);
	sta = *(int *)(*stack_a)->content;
	if (sta <= get_min(stack_b))
	{
		ret = ft_strjoin_ip(ret, pb(stack_a, stack_b), 1);
		ret = ft_strjoin_ip(ret, rb(stack_b), 1);
		return (ret);
	}
	else if (sta >= get_max(stack_b))
	{
		ret = ft_strjoin_ip(ret, reset(stack_b, 'b'), 1);
		ret = ft_strjoin_ip(ret, pb(stack_a, stack_b), 1);
		return (ret);
	}
	while (!((*(int *)(*stack_b)->content) <= sta
		&& (sta <= *(int *)ft_lstlast(*stack_b)->content)))
		ret = ft_strjoin_ip(ret, rrb(stack_b), 1);
	ret = ft_strjoin_ip(ret, pb(stack_a, stack_b), 1);
	return (ret);
}

char	*sort(t_list **stack_a, t_list **stack_b, size_t n)
{
	char	*ret;
	size_t	lenleft;
	size_t	sorted;

	ret = ft_calloc(1, 1);
	if (!ret)
		return (NULL);
	while (n <= (size_t)ft_lstsize(*stack_a))
	{
		lenleft = (size_t)ft_lstsize(*stack_a);
		while (lenleft >= n)
		{
			ret = ft_strjoin_ip(ret, push_bloc(stack_a, stack_b, n, 1), 1);
			ret = ft_strjoin_ip(ret, merge(stack_a, stack_b,
							ft_min(lenleft - n, n)), 1);
			ret = ft_strjoin_ip(ret, reset(stack_b, 'b'), 1);
			sorted = ft_lstsize(*stack_b);
			ret = ft_strjoin_ip(ret, push_bloc(stack_a, stack_b,
						sorted, -1), 1);
			ret = ft_strjoin_ip(ret, rotate_i(stack_a, sorted), 1);
			lenleft -= sorted;
		}
		ret = ft_strjoin_ip(ret, rotate_i(stack_a, lenleft), 1);
		n *= 2;
	}
	return (ret);
}
