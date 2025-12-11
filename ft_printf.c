/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:40 by adraji            #+#    #+#             */
/*   Updated: 2025/12/11 14:47:40 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_switch(va_list args, const char fms)
{
	char	*str;
	int		count;

	if (fms == 'd' || fms == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (fms == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else if (fms == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (fms == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (fms == 'p')
		str = (ft_address(va_arg(args, void *)));
	else if (fms == 'x' || fms == 'X')
		str = ft_hexa(va_arg(args, unsigned int), fms);
	else if (fms == '%')
		return (ft_putchar('%'));
	else
	{
		count = ft_putchar('%') + ft_putchar(fms);
		if (count < 1)
			return (-1);
		return (count);
	}
	return (ft_putstr(str));	
}

int	ft_printf(const char *fms, ...)
{
	size_t	i;
	va_list	args;
	int		save;
	int		count;

	if (!fms)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, fms);
	while (fms[i])
	{
		if (fms[i] != '%')
		{
			save = ft_putchar(fms[i++]);
			if (save < 0)
				return (va_end(args), -1);
			count += save;
		}
		else if (fms[++i])
		{
			save = ft_switch(args, fms[i]);
			if (save < 0)
				return (va_end(args), -1);
			count += save;
			i++;
		}
	}
	return (va_end(args), count);
}
