/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:09:07 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/20 14:23:03 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int		ft_find_nl(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static	void	set_next_l(char **str, int fd)
{
	int		nl;
	char	*tmp;

	nl = ft_find_nl(str[0]);
	if (str[0][nl] == '\n')
	{
		tmp = ft_strdup(str[0] + nl + 1);
		free(str[0]);
		str[0] = tmp;
	}
	else
	{
		ft_putnbr(fd);
		ft_strdel(&str[0]);}
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static	char	*save[1];
	char			*tmp;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	save[0] = (!(save[0]) ? ft_strnew(1) : save[0]);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(save[0], buf);
		free(save[0]);
		save[0] = tmp;
		if (ft_find_nl(buf) < ret)
			break ;
	}
	if (ret == 0 && (!save[0] || save[0][0] == '\0'))
		return (0);
	*line = ft_strsub(save[0], 0, ft_find_nl(save[0]));
	set_next_l(save, fd);
	return (1);
}
