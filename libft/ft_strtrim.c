/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:13:49 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/08 18:50:42 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_cssp(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static	int	ft_cesp(const char *s)
{
	int i;

	i = (int)ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	return (i + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*trim;

	if (!s)
		return (NULL);
	if (ft_cesp(s) - ft_cssp(s) < 0)
		return (ft_strnew(0));
	if (ft_cesp(s) - ft_cssp(s) == (int)ft_strlen(s))
	{
		if (!(trim = ft_strdup(s)))
			return (NULL);
		return (trim);
	}
	if (!(trim = ft_strsub(s, ft_cssp(s), (size_t)(ft_cesp(s) - ft_cssp(s)))))
		return (NULL);
	return (trim);
}
