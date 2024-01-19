/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:09:20 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/19 14:22:36 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **array, char *nb, int index)
{
	index -= 1;
	while (index >= 0)
	{
		if (ft_atoi(nb) == ft_atoi(array[index]))
			return (0);
		index--;
	}
	return (1);
}

int	check_error(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		if (ft_strlen(array[i]) == 1 && array[i][0] == '0')
		{
			if (check_double(array, array[i], i) == 0)
				return (0);
		}
		else
		{
			if (check_double(array, array[i], i) == 0 || ft_atoi(array[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	final_check(int ac, char **av)
{
	char	**array;
	int		i;

	i = -1;
	if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		if (!array)
			return (0);
		if (check_error(array) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		free_double_array(array);
	}
	else
	{
		if (check_error(av + 1) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

t_Dlist	*get_params(int ac, char **av)
{
	int		i;
	t_Dlist	*lst;
	t_Dlist	*new_elem;

	lst = ft_dlstnew(ft_atoi(av[1]));
	if (!lst)
		return (NULL);
	i = 2;
	while (i < ac)
	{
		new_elem = ft_dlstnew(ft_atoi(av[i]));
		if (!new_elem)
		{
			free_lst(&lst);
			return (NULL);
		}
		ft_dlstadd_back(&lst, new_elem);
		i++;
	}
	return (lst);
}

t_Dlist	*get_params_str(char **param_array)
{
	int		i;
	t_Dlist	*lst;
	t_Dlist	*new_elem;

	lst = NULL;
	i = 0;
	while (param_array[i] != 0)
	{
		new_elem = ft_dlstnew(ft_atoi(param_array[i]));
		if (!new_elem)
		{
			free_double_array(param_array);
			free_lst(&lst);
			return (NULL);
		}
		ft_dlstadd_back(&lst, new_elem);
		i++;
	}
	free_double_array(param_array);
	return (lst);
}
