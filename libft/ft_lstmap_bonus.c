/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:34:45 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/13 14:23:59 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
static void	*free_lst(t_list *lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;

	if (!lst)
		return (NULL);
	new_lst = ft_calloc(1, sizeof(t_list));
	if (!new_lst)
		return (NULL);
	current = new_lst;
	while (lst)
	{
		current->content = f(lst->content);
		lst = lst->next;
		if (lst)
		{
			current->next = ft_calloc(1, sizeof(t_list));
			if (!(current->next))
				return (free_lst(new_lst, del));
			current = current->next;
		}
	}
	current->next = NULL;
	return (new_lst);
}

static void	*free_lst(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		del(lst->content);
		free(lst);
		lst = next;
	}
	return (NULL);
}
