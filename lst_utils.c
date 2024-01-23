/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:09:14 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/22 15:17:07 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_Dlist **lst)
{
	if (*lst)
	{
		while ((*lst)->next)
		{
			*lst = (*lst)->next;
			free((*lst)->back);
		}
		free(*lst);
	}
}

int	lst_len(t_Dlist **lst)
{
	t_Dlist	*lst_copy;
	int		length;

	if (!*lst)
		return (0);
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
		return (NULL);
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
