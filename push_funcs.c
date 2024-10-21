/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:45:15 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/21 13:49:59 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	pa(int **stack_a, int **stack_b);

void	pa(int **stack_a, int **stack_b)
{
	if (!*stack_b)
		return ;
	**stack_b = **stack_a;
}