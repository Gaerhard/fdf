/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:13:25 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/08 11:02:50 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = ft_strlen(s1);
	if (!(dest = (char *)malloc(sizeof(*dest) * (i + 1))))
		return (NULL);
	dest = ft_strcpy(dest, s1);
	return (dest);
}
