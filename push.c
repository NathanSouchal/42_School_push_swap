/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:23:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/08 12:12:49 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_Dlist **stack_1, t_Dlist **stack_2)
{
	t_Dlist	*temp;
	t_Dlist	*head_next;

	if (*stack_2 && stack_1 != NULL && stack_2 != NULL)
	{
		head_next = (*stack_2)->next;
		temp = *stack_1;
		*stack_1 = *stack_2;
		(*stack_1)->next = temp;
		head_next->back = NULL;
		*stack_2 = head_next;
	}
}

void	push_a(t_Dlist **stack_a, t_Dlist **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	push_b(t_Dlist **stack_a, t_Dlist **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
