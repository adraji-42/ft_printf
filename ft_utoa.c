/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:34:54 by adraji            #+#    #+#             */
/*   Updated: 2025/12/12 07:42:12 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_nbrlen(unsigned int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	ft_revers(char *s)
{
	int		i;
	int		j;
	char	t;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		t = s[i];
		s[i++] = s[j];
		s[j--] = t;
	}
}

char	*ft_utoa(unsigned int n)
{
	char	*nb;
	int		i;

	nb = malloc(sizeof(char) * (ft_nbrlen(n) + 1));
	if (!nb)
		return (NULL);
	i = 0;
	if (n == 0)
		nb[i++] = '0';
	while (n > 0)
	{
		nb[i++] = (n % 10) + '0';
		n /= 10;
	}
	nb[i] = '\0';
	ft_revers(nb);
	return (nb);
}
