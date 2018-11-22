/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:16:53 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/19 16:15:25 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_check_sep(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

static	int		ft_count_words(char *str, char *cs)
{
	int i;
	int	words;

	i = 1;
	words = ft_check_sep(str[0], cs) ? 1 : 0;
	if (str[i] == '\0')
		return (words);
	while (str[i])
	{
		if (ft_check_sep(str[i], cs)
			&& (!(ft_check_sep(str[i - 1], cs))))
			words++;
		i++;
	}
	return (words);
}

static	size_t	ft_s_w(char *str, char *cs)
{
	size_t i;

	i = 0;
	while (ft_check_sep(str[i], cs) && str[i])
		i++;
	return (i);
}

char			**ft_split(char *str, char *cs)
{
	int		words;
	int		i;
	int		j;
	char	**tab;

	words = ft_count_words(str, cs);
	tab = (char **)malloc(sizeof(tab) * (words + 1));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (i < words && str[j])
	{
		if (ft_check_sep(str[j], cs)
				&& (j == 0 || !(ft_check_sep(str[j - 1], cs))))
		{
			tab[i] = malloc(sizeof(char*) * (ft_s_w(str + j + 1, cs)));
			tab[i] = ft_strncpy(tab[i], (const char*)str + j, \
					ft_s_w(str + j, cs));
			i++;
		}
		j++;
	}
	tab[i] = NULL;
	return (tab);
}
