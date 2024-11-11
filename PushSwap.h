/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:25:50 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/11 14:49:58 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>





#include <stdio.h>
void	print_list(t_list **lst1, t_list **lst2);






int		main(int argc, char *argv[]);
void	init(t_list **stack_a, t_list **stack_b);
void	merge(t_list **stack_a, t_list **stack_b, int size_a);
int		insert(t_list **stack_a, t_list **stack_b, int size_a);
void	sort(t_list **stack_a, t_list **stack_b, int n);

void	push(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir);

void	revrotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	revrotate_i(t_list **stack, int n, char ab);

void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rotate_i(t_list **stack, int n, char ab);

void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	goto_val(t_list **stack, char ab, int value);
t_list	**parse_input(int argc, char *argv[]);
void	add_to_stack(t_list **stack, char *str);
void	exit_gracefully(t_list **stack_a, t_list **stack_b, int status);
int		minichecker(t_list **stack_a, t_list **stack_b);

void	add_instr(char *str, bool print);
t_list	**simplify(t_list **out, int last_size);
t_list	**cut(t_list **out, int start, int end);
void	write_output(t_list **stack);

void	usort(t_list **stack_a, t_list **stack_b);
void	usort1(t_list **stack_a, t_list **stack_b, int order);
void	usort2(t_list **stack_a, t_list **stack_b, int order);
void	usort3(t_list **stack_a, t_list **stack_b, int order);

#endif