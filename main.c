/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/21 14:23:37 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"


int main(int argc, char *argv[])
{
    int     i;
    t_list  **stack_a;
    t_list  **stack_b;
    int     *tmp;
    t_list  *new_node;

    i = 1;
    printf("I HAVE %i elements\n", argc);
    stack_a = ft_calloc(1, sizeof(t_list *));
    stack_b = ft_calloc(1, sizeof(t_list *));
    printf("I HAVE %i elements\n", argc);
    while (i < argc)
    {
        tmp = ft_calloc(1, sizeof(int));
        *tmp = ft_atoi(argv[i]);
        new_node = ft_lstnew(tmp);
        printf("adding %i %i\n", i, *tmp);
        ft_lstadd_front(stack_a, new_node);
        i++;
        print_list(stack_a);
    }
    sa(stack_a);
    return (1);
}

