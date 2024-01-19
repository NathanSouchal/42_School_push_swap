/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:30:01 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/18 09:55:52 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first_sup(int nb, t_Dlist **stack)
{
	int		first_sup;
	t_Dlist	*stack_copy;

	stack_copy = *stack;
	while (stack_copy)
	{
		if (nb < stack_copy->value)
			first_sup = stack_copy->value;
		stack_copy = stack_copy->next;
	}
	stack_copy = *stack;
	while (stack_copy)
	{
		if (nb < stack_copy->value && stack_copy->value <= first_sup)
			first_sup = stack_copy->value;
		stack_copy = stack_copy->next;
	}
	return (first_sup);
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	lst_sorted(t_Dlist **lst)
{
	t_Dlist	*lst_copy;

	lst_copy = *lst;
	while (lst_copy->next)
	{
		if (lst_copy->value > lst_copy->next->value)
			return (0);
		lst_copy = lst_copy->next;
	}
	return (1);
}
