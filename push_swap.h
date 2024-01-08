/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:54:25 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/08 11:25:53 by nsouchal         ###   ########.fr       */
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
	struct s_Dlist	*back;
	struct s_Dlist	*next;
}	t_Dlist;

t_Dlist	*ft_dlstnew(int content);
t_Dlist	*get_params(int ac, char **av);
t_Dlist	*get_params_str(char *str);
void	ft_dlstadd_back(t_Dlist **lst, t_Dlist *new);
void	ft_dlstadd_front(t_Dlist **lst, t_Dlist *new);
t_Dlist	*ft_dlstlast(t_Dlist *lst);
int		final_check(int ac, char **av);
void	print_list(t_Dlist **lst);
int		lst_len(t_Dlist **lst);
t_Dlist	*ft_dlstlast(t_Dlist *lst);
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

#endif
