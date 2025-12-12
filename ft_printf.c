/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:40 by adraji            #+#    #+#             */
/*   Updated: 2025/12/12 07:40:43 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_switch(va_list args, const char fms)
{
	char	*str;
	int		save;

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
		str = ft_strdup("% ");
		str[1] = fms;
	}
	save = ft_putstr(str);
	free (str);
	return (save);
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
			save = ft_putchar(fms[i++]);
		else if (fms[++i])
			save = ft_switch(args, fms[i++]);
		if (save < 0)
		{
			va_end(args);
			return (-1);
		}
		count += save;
	}
	va_end(args);
	return (count);
}
