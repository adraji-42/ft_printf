/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:01:13 by adraji            #+#    #+#             */
/*   Updated: 2025/12/02 10:28:06 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_number(const char *nptr, size_t i, int s)
{
	unsigned long	n;
	int				digit;

	n = 0;
	while (nptr[i] && nptr[i] < 58 && nptr[i] > 47)
	{
		digit = nptr[i] - 48;
		if (n > LONG_MAX / 10)
		{
			if (s < 0)
				return (0);
			return (-1);
		}
		n *= 10;
		if (n > LONG_MAX / 10 && digit > 7)
		{
			if (s < 0)
				return (0);
			return (-1);
		}
		n += digit;
		i++;
	}
	return ((long)n);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	long	n;
	int		s;

	i = 0;
	n = 0;
	s = 1;
	while (nptr[i] && ((nptr[i] == ' ') || (nptr[i] < 14 && nptr[i] > 8)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	n = ft_number(nptr, i, s);
	return (n * s);
}
