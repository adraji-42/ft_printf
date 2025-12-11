/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:34:54 by adraji            #+#    #+#             */
/*   Updated: 2025/12/02 12:43:29 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizenb(int n)
{
	size_t			size;
	unsigned int	nb;

	size = 0;
	nb = (unsigned int)n;
	if (nb <= 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size + (n <= 0));
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

char	*ft_itoa(int n)
{
	char			*nb;
	int				i;
	unsigned int	nbr;

	nb = malloc(sizeof(char) * (ft_sizenb(n) + 1));
	if (!nb)
		return (NULL);
	i = 0;
	if (n == 0)
		nb[i++] = '0';
	if (n < 0)
		nbr = - (unsigned int)n;
	else
		nbr = n;
	while (nbr > 0)
	{
		nb[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		nb[i++] = '-';
	nb[i] = '\0';
	ft_revers(nb);
	return (nb);
}
