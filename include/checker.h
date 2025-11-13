/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:10:00 by vviterbo          #+#    #+#             */
/*   Updated: 2025/09/02 11:38:30 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "PushSwap.h"

int	main(int argc, char *argv[]);
int	do_operation(t_list **stack_a, t_list **stack_b, char *op, int len);

#endif