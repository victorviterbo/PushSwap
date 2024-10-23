/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:27:51 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/23 15:35:14 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_list	*pop(t_list **lst);
t_list	**push(t_list **lst, t_list *elem);

t_list	*pop(t_list **lst)
{
	t_list	*ret;

	ret = *lst;
	*lst = (*lst)->next;
	ret->next = NULL;
	return (ret);
}

t_list	**push(t_list **lst, t_list *elem)
{
	elem->next = *lst;
	return (&elem);
}
