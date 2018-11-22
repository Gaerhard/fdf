/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:56:31 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/08 12:34:06 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int tmp;

	i = 0;
	tmp = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			tmp = i;
		i++;
	}
	if (tmp >= 0)
		return ((char *)(s + tmp));
	if (!c)
		return ((char *)(s + i));
	return (NULL);
}
