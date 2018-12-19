/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:39:58 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/19 16:16:21 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_l(t_env *e, int min, int max)
{
	e->v1.x = min;
	e->v2.x = max;
}

void			scale_map(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < e->m.nl)
	{
		x = -1;
		while (++x < e->m.nc)
		{
			TABZ = TABZ * e->move.sc;
		}
	}
}

double			get_vertical_scale(t_env *e)
{
	t_lim lim;

	lim = get_limits(e);
	return ((double)e->m.nl / ((double)lim.z_max * 10));
}

void	set_levels(t_env *e, int x, int y)
{
	if (TABZ == 0)
	{
		e->v1.c = 0x00FFFFFF;
		e->v2.c = 0x00FFFFFF;
		fill_l(e, 0, 0);
	}
	else if (TABZ >= 1 && TABZ < e->delta_x / 2)
	{
		e->v1.c = 0x000000FF;
		e->v2.c = 0x00FFFF00;
		fill_l(e, 1, e->delta_x / 2);
	}
	else if (TABZ >= e->delta_x / 2 && TABZ < e->delta_x)
	{
		e->v1.c = 0x00FFFF00;
		e->v2.c = 0x00FF0000;
		fill_l(e, e->delta_x / 2, e->delta_x);
	}
}
