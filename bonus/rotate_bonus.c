/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:15:43 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/19 12:28:26 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a_bonus(t_Dlist **stack_a)
{
	rotate(stack_a);
}

void	rotate_b_bonus(t_Dlist **stack_b)
{
	rotate(stack_b);
}

void	rotate_ab_bonus(t_Dlist **stack_a, t_Dlist **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
