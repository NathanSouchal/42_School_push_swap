/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:12:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/19 08:53:34 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_b_befmed(t_Dlist **stack_a, t_Dlist **stack_b, t_Dlist *cheapest)
{
	if (cheapest->position < 0)
	{
		if (cheapest->a_moves > cheapest->b_moves)
		{
			while (cheapest->a_moves-- - cheapest->b_moves)
				rotate_a(stack_a);
			while (cheapest->b_moves--)
				rotate_ab(stack_a, stack_b);
		}
		else
		{
			while (cheapest->b_moves-- - cheapest->a_moves)
				rotate_b(stack_b);
			while (cheapest->a_moves--)
				rotate_ab(stack_a, stack_b);
		}
	}
	else
	{
		while (cheapest->a_moves--)
			reverse_rotate_a(stack_a);
		while (cheapest->b_moves--)
			rotate_b(stack_b);
	}
}

void	moves_b_aftmed(t_Dlist **stack_a, t_Dlist **stack_b, t_Dlist *cheapest)
{
	if (cheapest->position > 0)
	{
		if (cheapest->a_moves > cheapest->b_moves)
		{
			while (cheapest->a_moves-- - cheapest->b_moves)
				reverse_rotate_a(stack_a);
			while (cheapest->b_moves--)
				reverse_rotate_ab(stack_a, stack_b);
		}
		else
		{
			while (cheapest->b_moves-- - cheapest->a_moves)
				reverse_rotate_b(stack_b);
			while (cheapest->a_moves--)
				reverse_rotate_ab(stack_a, stack_b);
		}
	}
	else
	{
		while (cheapest->a_moves--)
			rotate_a(stack_a);
		while (cheapest->b_moves--)
			reverse_rotate_b(stack_b);
	}
}

void	do_moves_b(t_Dlist **stack_a, t_Dlist **stack_b)
{
	int		min;
	int		f_u_i;
	int		index_min;
	t_Dlist	*cheapest;

	min = find_lst_min(stack_b);
	cheapest = find_cheapest(stack_a);
	f_u_i = find_index(find_first_under(cheapest->value, stack_b), stack_b);
	index_min = find_index(min, stack_b);
	if (cheapest->value < min)
	{
		if (index_min < (lst_len(stack_b) / 2))
			moves_b_befmed(stack_a, stack_b, cheapest);
		else
			moves_b_aftmed(stack_a, stack_b, cheapest);
	}
	else
	{
		if (f_u_i <= (lst_len(stack_b) / 2))
			moves_b_befmed(stack_a, stack_b, cheapest);
		else
			moves_b_aftmed(stack_a, stack_b, cheapest);
	}
	push_b(stack_a, stack_b);
}
