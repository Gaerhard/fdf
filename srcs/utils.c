/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:56:47 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/08 15:30:32 by gaerhard         ###   ########.fr       */
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
int		ft_color(t_env *e, int x, int y)
{
	double	perc;
	int		red;
	int		green;
	int		blue;

	if (e->delta_x > e->delta_y)
		perc = percent(e->v1.x, e->v2.x, x);
	else
		perc = percent(e->v1.y, e->v2.y, y);
	red = get_light((e->v1.c >> 16) & 0xFF, (e->v2.c >>16) & 0xFF, perc);
	green = get_light((e->v1.c >> 8) & 0xFF, (e->v2.c >> 8) & 0xFF, perc);
	blue = get_light((e->v1.c) & 0xFF, (e->v2.c) & 0xFF, perc);
	return ((red <<16) | (green << 8)| blue);
}
