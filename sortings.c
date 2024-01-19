/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:06:44 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/19 14:13:37 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort_a(t_Dlist **stack)
{
	int	min;
	int	index_min;
	int	median;

	min = find_lst_min(stack);
	index_min = find_index(min, stack);
	median = lst_len(stack) / 2;
	if (index_min <= median)
	{
		while (index_min--)
			rotate_a(stack);
	}
	else
	{
		while (lst_len(stack) - index_min++)
			reverse_rotate_a(stack);
	}
}

void	sort_2_a(t_Dlist **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		swap_a(stack);
}

void	sort_3(t_Dlist **stack)
{
	t_Dlist	*last;
	t_Dlist	*second;

	last = ft_dlstlast(*stack);
	second = (*stack)->next;
	if ((*stack)->value > second->value && (*stack)->value < last->value)
		swap_a(stack);
	else if ((*stack)->value < second->value && second->value > last->value
		&& (*stack)->value < last->value)
	{
		reverse_rotate_a(stack);
		swap_a(stack);
	}
	else if ((*stack)->value > second->value && second->value < last->value)
		rotate_a(stack);
	else if ((*stack)->value > second->value && second->value > last->value)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else if ((*stack)->value < second->value && second->value > last->value
		&& (*stack)->value > last->value)
		reverse_rotate_a(stack);
}

void	final_sort(t_Dlist **stack_a, t_Dlist **stack_b)
{
	if (lst_sorted(stack_a) == 1)
		return ;
	else if (lst_len(stack_a) == 2)
		sort_2_a(stack_a);
	else if (lst_len(stack_a) == 3)
		sort_3(stack_a);
	else
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		while (lst_len(stack_a) > 3)
		{
			calculate_cost(stack_a, stack_b);
			do_moves_b(stack_a, stack_b);
		}
		sort_3(stack_a);
		while (lst_len(stack_b))
			do_moves_a(stack_a, stack_b);
		final_sort_a(stack_a);
	}
	free_lst(stack_a);
}
