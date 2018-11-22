/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:40:05 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/09 13:58:15 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size(int n)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n <= -10 || n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_size(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		res[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	res[len - 1] = (n % 10) + '0';
	return (res);
}
