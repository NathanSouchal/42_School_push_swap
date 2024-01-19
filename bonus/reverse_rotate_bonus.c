/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/19 12:28:19 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_a_bonus(t_Dlist **stack_a)
{
	reverse_rotate(stack_a);
}

void	reverse_rotate_b_bonus(t_Dlist **stack_b)
{
	reverse_rotate(stack_b);
}

void	reverse_rotate_ab_bonus(t_Dlist **stack_a, t_Dlist **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
