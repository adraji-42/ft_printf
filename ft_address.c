/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:48 by adraji            #+#    #+#             */
/*   Updated: 2025/12/07 12:21:07 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_addresslen(size_t n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_address(void *p)
{
	int		i;
	int		len;
	char	*add;
	size_t	address;

	if (!p)
		return (ft_strdup("(nil)"));
	address = (size_t)p;
	len = 2 + ft_addresslen(address);
	add = malloc(sizeof(char) * (len + 1));
	if (!add)
		return (NULL);
	add[0] = '0';
	add[1] = 'x';
	i = len - 1;
	while (i > 1)
	{
		add[i--] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	add[len] = '\0';
	return (add);
}
