/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:56:47 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/20 16:53:33 by gaerhard         ###   ########.fr       */
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

t_lim			get_limits(t_env *e)
{
	int x;
	int y;
	t_lim lim;

	lim.z_min = 2147483647;
	lim.z_max = -2147483648;
	y = -1;
	while (++y < e->m.nl)
	{
		x = -1;
		while (++x < e->m.nc)
		{
			lim.z_min = (lim.z_min > TABZ) ? TABZ : lim.z_min;
			lim.z_max = (lim.z_max < TABZ) ? TABZ : lim.z_max;
		}
	}
	e->delta_x = lim.z_max - lim.z_min;
	e->delta_y = 0;
	e->v1.x = lim.z_min;
	e->v2.x = lim.z_max;
	return (lim);
}

int				ft_color(t_env *e, int x, int y)
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

void			set_colors(t_env *e)
{
	int		x;
	int		y;
	t_lim	lim;

	y = -1;
	lim = get_limits(e);
	while (++y < e->m.nl)
	{
		x = -1;
		while (++x < e->m.nc)
		{
			set_levels(e, x, y, lim);
		//	TABC = ft_color(e, TABZ, TABZ);
		}
	}
}
