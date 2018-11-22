/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:14:42 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/09 13:59:04 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_check(char *s, char *needle)
{
	int i;

	i = 1;
	while (s[i] && needle[i])
	{
		if (s[i] != needle[i])
			return (0);
		i++;
	}
	if (needle[i] != '\0')
		return (0);
	return (1);
}

char			*ft_strnstr(const char *s, const char *needle, size_t len)
{
	int i;

	i = 0;
	if (s[0] == '\0' && needle[0] == '\0')
		return ((char *)needle);
	if (s[0] != '\0' && needle[0] == '\0')
		return ((char *)s);
	if (s[0] == '\0' && needle[0] != '\0')
		return (0);
	while (s[i] && (i + (int)ft_strlen(needle) <= (int)len))
	{
		if (s[i] == needle[0])
		{
			if (ft_check((char *)(s + i), (char *)needle) == 1)
				return ((char *)s + i);
		}
		i++;
	}
	return (0);
}
