/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:08:23 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/08 19:03:14 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;

	if (!s1 || !s2)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strcat(ret, s2);
	return (ret);
}
