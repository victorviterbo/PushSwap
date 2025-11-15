/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:25:50 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/15 12:23:22 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define EXIT_SILENTLY 2
# define INIT_PTR 3

# include "../lib/libft/libft.h"
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>

//main.c
int		main(int argc, char *argv[]);
void	reinsert(t_list **stack_a, t_list **stack_b);
int		compute_cost(t_list **stack_a, t_list **stack_b, int b_value, int pos);
void	rotate_ab(t_list **stack_a, t_list **stack_b,
			int b_value, int best_i);
void	push_on_b(t_list **stack_a, t_list **stack_b);
//LIS.c
bool	*get_lis(t_list **stack_a);
int		*lst2arr(t_list **stack);
void	set_endpoint(int *lis_lens, int *arra, int n);
int		find_max(int *arr, int n);
bool	*propagate_backward(int *lis_lens, int *arra, int best, int n);
//utils.c
int		goto_val(t_list **stack, char ab, int value, bool dummy);
t_list	**parse_input(int argc, char *argv[]);
void	exit_gracefully(t_list **stack_a, t_list **stack_b, int status);
void	add_to_stack(t_list **stack, char *str);
int		get_n(t_list **stack, int n);
//write_out.c
void	add_instr(const char *str, bool print);
void	write_output(t_list **stack);
int		minichecker(t_list **stack_a, t_list **stack_b);
//minisort.c
void	minisort(t_list **stack_a, t_list **stack_b);
void	msort3(t_list **stack_a);
void	msort4(t_list **stack_a, t_list **stack_b);
void	msort5(t_list **stack_a, t_list **stack_b);
void	usort_swap(t_list **stack_a, char ab);
//push.c
void	push(t_list **stack_1, t_list **stack_2);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir);
//revrotate.c
void	revrotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	revrotate_i(t_list **stack_1, t_list **stack_2, int n, char ab);
//rotate.c
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rotate_i(t_list **stack_1, t_list **stack_2, int n, char ab);
//swap.c
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

#endif