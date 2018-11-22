/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:17:09 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/10 12:21:51 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_check_args(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = 0;
		if (base[i] < 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

static	int		ft_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static	int		ft_to_base_ten(char *str, char *base)
{
	int i;
	int res;
	int	signe;
	int	s_base;

	i = 0;
	res = 0;
	signe = 1;
	s_base = 0;
	while (base[s_base])
		s_base++;
	if (str[i] == '-' || str[i] == '+')
		signe = (str[i++] == '-') ? -1 : 1;
	while (ft_in_base(str[i], base) > -1)
	{
		res = res * s_base + ft_in_base(str[i], base);
		i++;
	}
	return ((str[i]) ? 0 : res * signe);
}

static	char	*ft_from_ten_to_x(int nb, char *base_to)
{
	int		i;
	int		j;
	int		base_t;
	char	*num;

	i = 0;
	base_t = 0;
	while (base_to[base_t])
		base_t++;
	if (!(num = malloc(sizeof(*num) * 32)))
		return (0);
	while (nb >= base_t)
	{
		j = 0;
		while (nb % base_t > j)
			j++;
		num[i++] = base_to[j];
		nb = nb / base_t;
	}
	j = 0;
	while (nb % base_t > j)
		j++;
	num[i] = base_to[j];
	num[i + 1] = '\0';
	return (num);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_ten;
	char	*num;
	char	tmp;
	int		i;
	int		j;

	if (!ft_check_args(base_from) || !ft_check_args(base_to))
		return (0);
	base_ten = ft_to_base_ten(nbr, base_from);
	num = ft_from_ten_to_x(base_ten, base_to);
	j = 0;
	i = 0;
	while (num[i])
		i++;
	while (i - 1 > j)
	{
		tmp = num[j];
		num[j] = num[i - 1];
		num[i - 1] = tmp;
		i--;
		j++;
	}
	return (num);
}
