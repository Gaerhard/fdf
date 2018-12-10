/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:20:48 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/08 18:59:28 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
static int		px(int x, int y)
{
	return (2 * (x + y));
}

static int		py(int x, int y)
{
	return (y - x);
}

static	t_env	*calc_coords(t_env *e)
{
	e->v1.x = px(e->x, e->y) * e->m.scale;
	e->v1.z = e->m.tab[e->y][e->x] * e->sc;
	e->v1.y = py(e->x, e->y) * e->m.scale + e->m.height / 2 - e->v1.z;
	e->v2.x = px(e->x + 1, e->y) * e->m.scale;
	e->v2.z = e->m.tab[e->y][e->x + 1] * e->sc;
	e->v2.y = py(e->x + 1, e->y) * e->m.scale + e->m.height / 2 - e->v2.z;
	if (e->v1.z <= 0)
		e->v1.c = 0x00009FFF;
	else if (e->v1.z >= 1 && e->v1.z <= 40)
		e->v1.c = 0x00009F40 + (e->v1.z * 0x00050000);
	else if (e->v1.z >= 41 && e->v1.z <= 70)
		e->v1.c = 0x00999999 + e->v1.z * 0x00111111;
	else if (e->v1.z >= 71)
		e->v1.c = 0x00FFFFFF;
	if (e->v2.z <= 0)
		e->v2.c = 0x00009FFF;
	else if (e->v2.z >= 1 && e->v2.z <= 40)
		e->v2.c = 0x00009F40 + (e->v2.z * 0x00050000);
	else if (e->v2.z >= 41 && e->v2.z <= 70)
		e->v2.c = 0x00999999 + e->v2.z * 0x00111111;
	else if(e->v2.z > 70)	
		e->v2.c = 0x00FFFFFF;
	return (e);
}

static	t_env	*calc_coords_2(t_env *e)
{
	e->v1.x = px(e->x, e->y) * e->m.scale;
	e->v1.z = e->m.tab[e->y][e->x] * e->sc;
	e->v1.y = py(e->x, e->y) * e->m.scale + e->m.height / 2 - e->v1.z;
	e->v2.x = px(e->x, e->y + 1) * e->m.scale;
	e->v2.z = e->m.tab[e->y + 1][e->x] * e->sc;
	e->v2.y = py(e->x, e->y + 1) * e->m.scale + e->m.height / 2 - e->v2.z;
	if (e->v1.z <= 0)
		e->v1.c = 0x00009FFF/* - ft_abs(e->v1.z)*/;
	else if (e->v1.z >= 1 && e->v1.z <= 40)
		e->v1.c = 0x00009F40 + (e->v1.z * 0x00050000);
	else if (e->v1.z >= 41 && e->v1.z <= 70)
		e->v1.c = 0x00999999 + e->v1.z * 0x00111111;
	else if (e->v1.z >= 71)
		e->v1.c = 0x00FFFFFF;
	if (e->v2.z <= 0)
		e->v2.c = 0x00009FFF/* - ft_abs(e->v2.z)*/;
	else if (e->v2.z >= 1 && e->v2.z <= 40)
		e->v2.c = 0x00009F40 + (e->v2.z * 0x00050000);
	else if (e->v2.z >= 41 && e->v2.z <= 70)
		e->v2.c = 0x00999999 + e->v2.z * 0x00111111;
	else if(e->v2.z > 70)	
		e->v2.c = 0x00FFFFFF;
	return (e);
}

/*
**	n = (ny > nx) ? ((1000 / m - m) / 4) * m : 250 / nx;
**	mlx = struct where everything related with mlx is saved
**	size = struct where the number of lines (.y) and columns (.x) is saved
**	tab = array of array of ints. the coords of the map are kept within it
**	*p = struct where the coords of the starting and final point of a line are
**			kept
**	s = struct to used to know what coord of tab am I working with
*/

void			draw_map(t_env *e)
{
	e->m.scale = (e->m.nc > e->m.nl) ?
		(e->m.width / 4) / e->m.nc : (e->m.width / 4) / e->m.nl;
	e->m.scale = (e->m.scale == 0) ? 1 : e->m.scale;
	e->y = -1;
	while (++(e->y) < e->m.nl)
	{
		e->x = -1;
		while (++(e->x) < e->m.nc - 1)
			draw_line(calc_coords(e));
	}
	e->y = -1;
	while (++(e->y) < e->m.nl - 1)
	{
		e->x = -1;
		while (++(e->x) < e->m.nc)
			draw_line(calc_coords_2(e));
	}
	mlx_put_image_to_window(e->p.mlx, e->p.win, e->img.ptr, 0, 0);
}
