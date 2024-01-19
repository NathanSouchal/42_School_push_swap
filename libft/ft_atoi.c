/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:22:14 by nsouchal          #+#    #+#             */
/*   Updated: 2024/01/17 14:27:24 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

int	ft_atoi(char *nptr)
{
	size_t			i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
		return (0);
	return (sign * (int)result);
}
