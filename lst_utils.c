/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:09:14 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/05 11:10:41 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_Dlist **lst)
{
	t_Dlist	*lst_copy;

	lst_copy = *lst;
	while (lst_copy != NULL)
	{
		ft_printf("%d\n", lst_copy->value);
		lst_copy = lst_copy->next;
	}
}

int	lst_len(t_Dlist **lst)
{
	t_Dlist	*lst_copy;
	int		length;

	lst_copy = *lst;
	length = 0;
	while (lst_copy != NULL)
	{
		length++;
		lst_copy = lst_copy->next;
	}
	return (length);
}

t_Dlist	*ft_dlstnew(int content)
{
	t_Dlist	*new_elem;

	new_elem = malloc(sizeof(t_Dlist));
	if (!new_elem)
		return (0);
	new_elem->value = content;
	new_elem->next = NULL;
	new_elem->back = NULL;
	return (new_elem);
}

t_Dlist	*ft_dlstlast(t_Dlist *lst)
{
	t_Dlist	*actual;

	if (!lst)
		return (0);
	actual = lst;
	while (actual)
	{
		if (!actual->next)
			return (actual);
		actual = actual->next;
	}
	return (actual);
}

void	ft_dlstadd_back(t_Dlist **lst, t_Dlist *new)
{
	t_Dlist	*last_elem;

	if (!*lst)
		*lst = new;
	else
	{
		last_elem = ft_dlstlast(*lst);
		last_elem->next = new;
		new->back = last_elem;
	}
}

// void	ft_dlstadd_front(t_Dlist **lst, t_Dlist *new)
// {
// 	if (*lst)
// 	{
// 		new->next = *lst;
// 		*lst = new;
// 	}
// 	else
// 		*lst = new;
// }
