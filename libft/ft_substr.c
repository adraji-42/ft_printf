/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:02:47 by adraji            #+#    #+#             */
/*   Updated: 2025/10/17 18:02:50 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
		return (ft_strdup(""));
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	return (ft_strncpy(sub, &s[start], len), sub);
}
