/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:18:42 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 17:50:25 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	print_list(t_list **lst1, t_list **lst2);

void	print_list(t_list **lst1, t_list **lst2)
{
	t_list	*current1;
	t_list	*current2;

	current1 = *lst1;
	current2 = *lst2;

	printf("---------------------------\n");
	while ((current1 && current1->content) || (current2 && current2->content))
	{
		if ((current1 && current1->content) && !(current2 && current2->content))
		{
			printf("%i\t\n", *((int *)current1->content));
			current1 = current1->next;
		}
		else if (!(current1 && current1->content) && (current2 && current2->content))
		{
			printf("\t%i\n", *((int *)current2->content));
			current2 = current2->next;
		}
		else
		{
			printf("%i\t%i\n", *((int *)current1->content), *((int *)current2->content));
			current1 = current1->next;
			current2 = current2->next;
		}
	}
	printf("---------------------------\n");
	return ;
}