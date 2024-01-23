/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:56:22 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/22 15:15:26 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int nb, t_Dlist **stack)
{
	int		index;
	int		i;
	t_Dlist	*stack_copy;

	stack_copy = *stack;
	i = 0;
	index = -1;
	while (stack_copy)
	{
		if (stack_copy->value == nb)
			index = i;
		i++;
		stack_copy = stack_copy->next;
	}
	return (index);
}

t_Dlist	*find_cheapest(t_Dlist **stack)
{
	t_Dlist	*stack_copy;
	int		cost;
	t_Dlist	*cheapest;

	stack_copy = *stack;
	cost = stack_copy->cost;
	cheapest = stack_copy;
	while (stack_copy)
	{
		if (stack_copy->cost < cost)
		{
			cheapest = stack_copy;
			cost = stack_copy->cost;
		}
		stack_copy = stack_copy->next;
	}
	return (cheapest);
}

int	find_first_under(int nb, t_Dlist **stack)
{
	int		first_under;
	t_Dlist	*stack_copy;

	stack_copy = *stack;
	while (stack_copy)
	{
		if (nb > stack_copy->value)
			first_under = stack_copy->value;
		stack_copy = stack_copy->next;
	}
	stack_copy = *stack;
	while (stack_copy)
	{
		if (nb > stack_copy->value && stack_copy->value >= first_under)
			first_under = stack_copy->value;
		stack_copy = stack_copy->next;
	}
	return (first_under);
}

int	find_lst_min(t_Dlist **stack)
{
	int		min;
	t_Dlist	*stack_copy;

	stack_copy = *stack;
	min = stack_copy->value;
	while (stack_copy)
	{
		if (stack_copy->value < min)
			min = stack_copy->value;
		stack_copy = stack_copy->next;
	}
	return (min);
}

int	find_lst_max(t_Dlist **stack)
{
	int		max;
	t_Dlist	*stack_copy;

	stack_copy = *stack;
	max = INT_MIN;
	while (stack_copy)
	{
		if (stack_copy->value > max)
			max = stack_copy->value;
		stack_copy = stack_copy->next;
	}
	return (max);
}
