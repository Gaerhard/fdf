/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:05:39 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/08 14:25:38 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_revcpy(void *dest, const void *src, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s2 = (unsigned char*)src + n - 1;
	s1 = (unsigned char*)dest + n - 1;
	while (n)
	{
		*s1 = *s2;
		s1--;
		s2--;
		n--;
	}
	return (dest);
}

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return (ft_revcpy(dest, src, n));
	return (ft_memcpy(dest, src, n));
}
