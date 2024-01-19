/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:19:50 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/19 14:11:12 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_instruction(t_Dlist **stack_a, t_Dlist **stack_b, char *instruction)
{
	if (!instruction)
		return ;
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		swap_a_bonus(stack_a);
	if (ft_strncmp(instruction, "sb\n", 3) == 0)
		swap_b_bonus(stack_b);
	if (ft_strncmp(instruction, "ss\n", 3) == 0)
		swap_ab_bonus(stack_a, stack_b);
	if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push_a_bonus(stack_a, stack_b);
	if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push_b_bonus(stack_a, stack_b);
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rotate_a_bonus(stack_a);
	if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rotate_b_bonus(stack_b);
	if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rotate_ab_bonus(stack_a, stack_b);
	if (ft_strncmp(instruction, "rra\n", 4) == 0)
		reverse_rotate_a_bonus(stack_a);
	if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		reverse_rotate_b_bonus(stack_b);
	if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		reverse_rotate_ab_bonus(stack_a, stack_b);
}

void	checker(t_Dlist **stack_a_bonus, t_Dlist **stack_b_bonus)
{
	char	*instruction;

	while (instruction != NULL)
	{
		instruction = get_next_line(0);
		do_instruction(stack_a_bonus, stack_b_bonus, instruction);
	}
	if (lst_sorted(stack_a_bonus) == 1 && *stack_b_bonus == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_Dlist	*stack_a_bonus;
	t_Dlist	*stack_b_bonus;
	char	**param_array;

	stack_a_bonus = NULL;
	stack_b_bonus = NULL;
	if (final_check(argc, argv) == 0 || argc == 1)
		return (0);
	else
	{
		if (argc == 2)
		{
			param_array = ft_split(argv[1], ' ');
			if (!param_array)
				return (0);
			stack_a_bonus = get_params_str(param_array);
		}
		else
		{
			stack_a_bonus = get_params(argc, argv);
		}
		if (!stack_a_bonus)
			return (0);
		checker(&stack_a_bonus, &stack_b_bonus);
	}
}
