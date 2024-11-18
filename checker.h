/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:10:00 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/18 12:29:17 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "pushswap.h"

int	main(int argc, char *argv[]);
int	do_operation(t_list **stack_a, t_list **stack_b, char *op, int len);

#endif