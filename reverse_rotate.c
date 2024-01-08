/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/08 12:08:55 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_Dlist **stack)
{
	t_Dlist	*last_elem;
	t_Dlist	*new_first;
	t_Dlist	*new_last;

	if (lst_len(stack) <= 2)
		swap(stack);
	else
	{
		last_elem = ft_dlstlast(*stack);
		new_first = last_elem;
		new_last = last_elem->back;
		new_last->next = NULL;
		new_first->next = *stack;
		new_first->back = NULL;
		*stack = new_first;
	}
}

void	reverse_rotate_a(t_Dlist **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_Dlist **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_Dlist **stack_a, t_Dlist **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
