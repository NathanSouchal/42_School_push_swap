/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:57:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/23 11:34:02 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Dlist	*stack_a;
	t_Dlist	*stack_b;
	char	**param_array;

	stack_b = NULL;
	stack_a = NULL;
	if (final_check(argc, argv) == 0 || argc == 1)
		return (0);
	else
	{
		if (argc == 2)
		{
			param_array = ft_split(argv[1], ' ');
			if (!param_array)
				return (0);
			stack_a = get_params_str(param_array);
		}
		else
		{
			stack_a = get_params(argc, argv);
		}
		if (!stack_a)
			return (0);
		final_sort(&stack_a, &stack_b);
	}
}
