/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:19:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/19 11:45:43 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	swap(int **stack);

void	swap(int **stack)
{
	int	tmp;

	tmp = *(*stack + 1);
	*(*stack + 1) = *(*stack);
	*(*stack) = tmp;
	return ;
}

void	sa(int **stack_a, int **stack_b)
{
	swap(stack_a);
	return ;
}

void	sb(int **stack_a, int **stack_b)
{
	swap(stack_b);
	return ;
}

void	ss(int **stack_a, int **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	return ;
}