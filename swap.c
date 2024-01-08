/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:19:20 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/08 12:13:30 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_Dlist **stack)
{
	int	temp;

	if (lst_len(stack) > 1)
	{
		temp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = temp;
	}
}

void	swap_a(t_Dlist **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_Dlist **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_ab(t_Dlist **stack_a, t_Dlist **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
