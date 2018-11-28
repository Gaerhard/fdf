/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:56:47 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/28 15:01:42 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int st, int end, int current)
{
	double place;
	double d;

	d = end - st;
	place = current - st;
	return ((d == 0) ? 1.0 : (place / d));
}

static int		get_light(int st, int end, double percentage)
{
	return ((int)((1 - percentage) * st + percentage * end));
}
/*
int		highest_point(int **tab, t_size size)
{
	int i;
	int j;
	int res;

	i = -1;
	res = 0;
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
		{
			if (tab[i][j] > res)
				res = tab[i][j];
		}
	}
	return (res);
}
*/
int		ft_color(t_point *p, int x, int y)
{
	double	perc;
	int		red;
	int		green;
	int		blue;

	if (ft_abs(p->x2 - p->x1) > ft_abs(p->y2 - p->y1))
		perc = percent(p->x1, p->x2, x);
	else
		perc = percent(p->y1, p->y2, y);
	red = get_light((p->color1 >> 16) & 0xFF, (p->color2 >>16) & 0xFF, perc);
	green = get_light((p->color1 >> 8) & 0xFF, (p->color2 >> 8) & 0xFF, perc);
	blue = get_light((p->color1) & 0xFF, (p->color2) & 0xFF, perc);
	return ((red <<16) | (green << 8)| blue);
}
