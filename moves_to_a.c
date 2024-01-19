/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:10:23 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/18 11:11:03 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_a_newmax(t_Dlist **stack_a, t_Dlist **stack_b, int index_max)
{
	int	median;

	median = lst_len(stack_a) / 2;
	if (index_max < median)
	{
		while (index_max-- + 1)
			rotate_a(stack_a);
	}
	else
	{
		while (lst_len(stack_a) - 1 - index_max++)
			reverse_rotate_a(stack_a);
	}
	push_a(stack_a, stack_b);
	rotate_a(stack_a);
}

void	moves_a_notnewmax(t_Dlist **stack_a, t_Dlist **stack_b, int fst_sup_i)
{
	int	median;

	median = lst_len(stack_a) / 2;
	if (fst_sup_i <= median)
	{
		while (fst_sup_i--)
			rotate_a(stack_a);
	}
	else
	{
		while (lst_len(stack_a) - fst_sup_i++)
			reverse_rotate_a(stack_a);
	}
	push_a(stack_a, stack_b);
}

void	do_moves_a(t_Dlist **stack_a, t_Dlist **stack_b)
{
	int	max;
	int	index_max;
	int	frst_sup_i;
	int	first_sup;

	max = find_lst_max(stack_a);
	index_max = find_index(max, stack_a);
	first_sup = find_first_sup((*stack_b)->value, stack_a);
	frst_sup_i = find_index(first_sup, stack_a);
	if ((*stack_b)->value > max)
		moves_a_newmax(stack_a, stack_b, index_max);
	else
		moves_a_notnewmax(stack_a, stack_b, frst_sup_i);
}
