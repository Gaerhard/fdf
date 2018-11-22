/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:00:33 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/08 17:06:27 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		ret[i] = s[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
