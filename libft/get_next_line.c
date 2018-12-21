/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:09:07 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/21 15:08:30 by gaerhard         ###   ########.fr       */
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

	nl = ft_find_nl(str[fd]);
	if (str[fd][nl] == '\n')
	{
		tmp = ft_strdup(str[fd] + nl + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else
		ft_strdel(&str[fd]);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static	char	*save[OPEN_MAX];
	char			*tmp;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	save[fd] = (!(save[fd]) ? ft_strnew(1) : save[fd]);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(save[fd], buf);
		free(save[fd]);
		save[fd] = tmp;
		if (ft_find_nl(buf) < ret)
			break ;
	}
	if (ret == 0 && (!save[fd] || save[fd][0] == '\0'))
		return (0);
	*line = ft_strsub(save[fd], 0, ft_find_nl(save[fd]));
	set_next_l(save, fd);
	return (1);
}
