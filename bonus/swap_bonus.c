/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:19:20 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/19 12:28:31 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a_bonus(t_Dlist **stack_a)
{
	swap(stack_a);
}

void	swap_b_bonus(t_Dlist **stack_b)
{
	swap(stack_b);
}

void	swap_ab_bonus(t_Dlist **stack_a, t_Dlist **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
