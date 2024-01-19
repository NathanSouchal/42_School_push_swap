/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:50:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/18 11:14:28 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_b_newmin(t_Dlist *stack_a_copy, t_Dlist **stack_b, int index_min)
{
	int	median;

	median = lst_len(stack_b) / 2;
	if (index_min < median)
	{
		if (stack_a_copy->position > 0)
			stack_a_copy->cost += index_min + 1;
		else if (stack_a_copy->cost < index_min + 1)
			stack_a_copy->cost = index_min + 1;
		stack_a_copy->b_moves = index_min + 1;
	}
	else
	{
		if (stack_a_copy->position < 0)
			stack_a_copy->cost += lst_len(stack_b) - index_min - 1;
		else if (stack_a_copy->cost < lst_len(stack_b) - index_min - 1)
			stack_a_copy->cost = lst_len(stack_b) - index_min - 1;
		stack_a_copy->b_moves = lst_len(stack_b) - index_min - 1;
	}
}

void	cost_b_notnwmin(t_Dlist *stack_a_copy, t_Dlist **stack_b, int f_u_i)
{
	int	median;

	median = lst_len(stack_b) / 2;
	if (f_u_i <= median)
	{
		if (stack_a_copy->position > 0)
			stack_a_copy->cost += f_u_i;
		else if (stack_a_copy->cost < f_u_i)
			stack_a_copy->cost = f_u_i;
		stack_a_copy->b_moves = f_u_i;
	}
	else
	{
		if (stack_a_copy->position < 0)
			stack_a_copy->cost += lst_len(stack_b) - f_u_i;
		else if (stack_a_copy->cost < lst_len(stack_b) - f_u_i)
			stack_a_copy->cost = lst_len(stack_b) - f_u_i;
		stack_a_copy->b_moves = lst_len(stack_b) - f_u_i;
	}
}

void	calculate_cost_b(t_Dlist **stack_a, t_Dlist **stack_b)
{
	t_Dlist	*stack_a_copy;
	int		first_under;
	int		f_u_i;
	int		min;
	int		index_min;

	stack_a_copy = *stack_a;
	min = find_lst_min(stack_b);
	index_min = find_index(min, stack_b);
	while (stack_a_copy)
	{
		if (stack_a_copy->value < min)
			cost_b_newmin(stack_a_copy, stack_b, index_min);
		else
		{
			first_under = find_first_under(stack_a_copy->value, stack_b);
			f_u_i = find_index(first_under, stack_b);
			cost_b_notnwmin(stack_a_copy, stack_b, f_u_i);
		}
		stack_a_copy->cost += 1;
		stack_a_copy = stack_a_copy->next;
	}
}

void	calculate_cost(t_Dlist **stack_a, t_Dlist **stack_b)
{
	int		index;
	int		position;
	t_Dlist	*stack_a_copy;
	t_Dlist	*stack_b_copy;

	stack_a_copy = *stack_a;
	stack_b_copy = *stack_b;
	index = -1;
	position = 0;
	while (++index <= (lst_len(stack_a) / 2))
	{
		stack_a_copy->position = -1;
		stack_a_copy->cost = index;
		stack_a_copy->a_moves = index;
		stack_a_copy = stack_a_copy->next;
	}
	while (index < lst_len(stack_a))
	{
		stack_a_copy->position = 1;
		stack_a_copy->cost = lst_len(stack_a) - index;
		stack_a_copy->a_moves = lst_len(stack_a) - index;
		stack_a_copy = stack_a_copy->next;
		index++;
	}
	calculate_cost_b(stack_a, stack_b);
}
