/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:20:48 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/20 19:36:07 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			px(double x, double y, t_env *e)
{
	if (e->projection == ISO)
		return ((x - y) * 0.86602540378);
	else if (e->projection == PARALLELE)
		return ((x - y));
	return (0);
}

double			py(double x, double y, t_env *e)
{
	if (e->projection == ISO)
		return ((x + y) * 0.5);
	else if (e->projection == PARALLELE)
		return (y);
	return (0);
}

static	t_env	*calc_coords(t_env *e, int x, int y)
{
	e->v1.x = px(TABX, TABY, e) * e->m.scale + e->move.x;
	e->v1.z = TABZ;
	e->v1.y = (py(TABX, TABY, e) - e->v1.z) * e->m.scale + e->move.y;
	e->v2.x = px(TABXX, TABYX, e) * e->m.scale + e->move.x;
	e->v2.z = TABZX;
	e->v2.y = (py(TABXX, TABYX, e) - e->v2.z) * e->m.scale + e->move.y;
	e->v1.c = TABC;
	e->v2.c = e->m.tab[y][x + 1].c;
	return (e);
}

static	t_env	*calc_coords_2(t_env *e, int x, int y)
{
	e->v1.x = px(TABX, TABY, e) * e->m.scale + e->move.x;
	e->v1.z = TABZ;
	e->v1.y = (py(TABX, TABY, e) - e->v1.z) * e->m.scale + e->move.y;
	e->v2.x = px(TABXY, TABYY, e) * e->m.scale + e->move.x;
	e->v2.z = TABZY;
	e->v2.y = (py(TABXY, TABYY, e) - e->v2.z) * e->m.scale + e->move.y;
	e->v1.c = TABC;
	e->v2.c = e->m.tab[y + 1][x].c;
	return (e);
}

/*
**	n = (ny > nx) ? ((1000 / m - m) / 4) * m : 250 / nx;
**	mlx = struct where everything related with mlx is saved
**	size = struct where the number of lines (.y) and columns (.x) is saved
**	tab = array of array of ints. the coords of the map are kept within it
**	*p = struct where the coords of the starting and final point of a line are
**			kept
**	s = struct used to know what coord of tab am I working with
*/

void			draw_map(t_env *e)
{
	int x;
	int y;

	if (e->start == 0)
	{
		e->m.scale = calc_scale(e);
		center_map(e);
	}
	y = -1;
	while (++y < e->m.nl)
	{
		x = -1;
		while (++x < e->m.nc - 1)
			draw_line(calc_coords(e, x, y));
	}
	y = -1;
	while (++y < e->m.nl - 1)
	{
		x = -1;
		while (++x < e->m.nc)
			draw_line(calc_coords_2(e, x, y));
	}
	mlx_put_image_to_window(e->p.mlx, e->p.win, e->img.ptr, 0, 0);
}
