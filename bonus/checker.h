/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:53:29 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/19 13:31:14 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "get_next_line.h"

void	push(t_Dlist **stack_1, t_Dlist **stack_2);
void	push_a_bonus(t_Dlist **stack_a, t_Dlist **stack_b);
void	push_b_bonus(t_Dlist **stack_a, t_Dlist **stack_b);
void	reverse_rotate(t_Dlist **stack);
void	reverse_rotate_a_bonus(t_Dlist **stack_a);
void	reverse_rotate_b_bonus(t_Dlist **stack_b);
void	reverse_rotate_ab_bonus(t_Dlist **stack_a, t_Dlist **stack_b);
void	rotate(t_Dlist **stack);
void	rotate_a_bonus(t_Dlist **stack_a);
void	rotate_b_bonus(t_Dlist **stack_b);
void	rotate_ab_bonus(t_Dlist **stack_a, t_Dlist **stack_b);
void	swap(t_Dlist **stack);
void	swap_a_bonus(t_Dlist **stack_a);
void	swap_b_bonus(t_Dlist **stack_b);
void	swap_ab_bonus(t_Dlist **stack_a, t_Dlist **stack_b);

#endif
