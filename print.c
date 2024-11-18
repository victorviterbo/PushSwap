/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:18:42 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/18 12:29:17 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

#include <libc.h>

void	print_list(t_list **lst1, t_list **lst2);

void	print_list(t_list **lst1, t_list **lst2)
{
	t_list	*current1;
	t_list	*current2;

	if (!lst1 || !lst2)
		return ;
	current1 = *lst1;
	current2 = *lst2;
	printf("---------------------------\n");
	while ((current1 && current1->i) || (current2 && current2->i))
	{
		if ((current1 && current1->i) && !(current2 && current2->i))
		{
			printf("%i\t\n", current1->i);
			current1 = current1->next;
		}
		else if (!(current1 && current1->i) && (current2 && current2->i))
		{
			printf("\t%i\n", current2->i);
			current2 = current2->next;
		}
		else
		{
			printf("%i\t%i\n", current1->i, current2->i);
			current1 = current1->next;
			current2 = current2->next;
		}
	}
	printf("---------------------------\n");
	return ;
}
