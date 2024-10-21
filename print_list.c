/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:18:42 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/21 14:25:28 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void    print_list(t_list **lst);

void    print_list(t_list **lst)
{
    t_list  *current;

    if (!lst || !*lst)
        return ;
    current = *lst;
    printf("---------------------------\n");
    while (current && current->content)
    {
        printf("%i\n", *((int *)current->content));
        current = current->next;
    }
    printf("---------------------------\n");
    
}