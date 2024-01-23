/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:54:25 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/22 15:17:11 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_Dlist
{
	int				value;
	int				cost;
	int				position;
	int				a_moves;
	int				b_moves;
	struct s_Dlist	*back;
	struct s_Dlist	*next;
}	t_Dlist;

t_Dlist	*ft_dlstnew(int content);
void	ft_dlstadd_back(t_Dlist **lst, t_Dlist *new);
t_Dlist	*ft_dlstlast(t_Dlist *lst);
int		lst_len(t_Dlist **lst);
void	print_cost(t_Dlist **lst);
void	free_lst(t_Dlist **lst);
int		lst_sorted(t_Dlist **lst);
void	free_double_array(char **array);

t_Dlist	*get_params(int ac, char **av);
t_Dlist	*get_params_str(char **param_array);
int		final_check(int ac, char **av);

void	set_lst_index(t_Dlist **stack);
int		find_index(int nb, t_Dlist **stack);
int		find_lst_min(t_Dlist **stack);
int		find_lst_max(t_Dlist **stack);
int		find_first_under(int nb, t_Dlist **stack);
int		find_first_sup(int nb, t_Dlist **stack);
t_Dlist	*find_cheapest(t_Dlist **stack);
void	do_moves_a(t_Dlist **stack_a, t_Dlist **stack_b);
void	calculate_cost(t_Dlist **stack_a, t_Dlist **stack_b);
void	do_moves_b(t_Dlist **stack_a, t_Dlist **stack_b);

void	swap(t_Dlist **stack);
void	swap_a(t_Dlist **stack_a);
void	swap_b(t_Dlist **stack_b);
void	swap_ab(t_Dlist **stack_a, t_Dlist **stack_b);
void	push_a(t_Dlist **stack_a, t_Dlist **stack_b);
void	push_b(t_Dlist **stack_a, t_Dlist **stack_b);
void	rotate_a(t_Dlist **stack_a);
void	rotate_b(t_Dlist **stack_b);
void	rotate_ab(t_Dlist **stack_a, t_Dlist **stack_b);
void	reverse_rotate_a(t_Dlist **stack_a);
void	reverse_rotate_b(t_Dlist **stack_b);
void	reverse_rotate_ab(t_Dlist **stack_a, t_Dlist **stack_b);

void	sort_2_a(t_Dlist **stack);
void	sort_3(t_Dlist **stack);
void	final_sort_a(t_Dlist **stack);
void	final_sort(t_Dlist **stack_a, t_Dlist **stack_b);

#endif
