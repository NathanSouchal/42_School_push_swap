/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:23:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/19 12:28:10 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_a_bonus(t_Dlist **stack_a, t_Dlist **stack_b)
{
	push(stack_a, stack_b);
}

void	push_b_bonus(t_Dlist **stack_a, t_Dlist **stack_b)
{
	push(stack_b, stack_a);
}
