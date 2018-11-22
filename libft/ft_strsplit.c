/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:56:01 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/09 13:47:44 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nwords(const char *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

static	int		ft_size_word(const char *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return ((size_t)size);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**res;
	int				n_word;
	int				i;
	unsigned int	index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	n_word = ft_nwords(s, c);
	if (!(res = (char **)malloc(sizeof(char*) * (n_word + 1))))
		return (NULL);
	while (n_word--)
	{
		while (s[i] == c && s[i])
			i++;
		if (!(res[index] = ft_strsub(s + i, 0, ft_size_word(&s[i], c))))
			return (NULL);
		i = i + ft_size_word(&s[i], c);
		index++;
	}
	res[index] = NULL;
	return (res);
}
