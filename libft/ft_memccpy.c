/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:13:14 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/07 17:47:38 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dest;
	while (i < n)
	{
		s2[i] = s1[i];
		if (s1[i] == (unsigned char)c)
			return (&s2[i + 1]);
		i++;
	}
	return (NULL);
}
