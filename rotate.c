/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:15:43 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/08 09:41:58 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_Dlist **stack)
{
	t_Dlist	*last_elem;
	t_Dlist	*new_first;
	t_Dlist	*new_last;

	last_elem = ft_dlstlast(*stack);
	new_first = (*stack)->next;
	new_last = *stack;
	new_first->back = NULL;
	new_last->next = NULL;
	new_last->back = last_elem;
	last_elem->next = new_last;
	*stack = new_first;
}

void	rotate_a(t_Dlist **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_Dlist **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_ab(t_Dlist **stack_a, t_Dlist **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
