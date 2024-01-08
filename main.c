/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:57:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/08 12:07:54 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Dlist	*stack_a;
	t_Dlist	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (final_check(argc, argv) == 0 || argc == 1)
		return (0);
	else
	{
		if (argc == 2)
			stack_a = get_params_str(argv[1]);
		else
			stack_a = get_params(argc, argv);
		reverse_rotate_a(&stack_a);
		print_list(&stack_a);
		reverse_rotate_a(&stack_a);
		print_list(&stack_a);
	}
}
