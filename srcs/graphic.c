/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:20:48 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/26 19:22:13 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		px(int x, int y)
{
	return (2 * (x + y));
}

static int		py(int x, int y)
{
	return (y - x);
}

static	t_point	*calc_coords(t_point *p, t_size size, int **tab, t_size s)
{
	(void)size;
	p->x1 = px(s.x, s.y) * p->scale;
	p->z1 = tab[s.y][s.x];
	p->y1 = py(s.x, s.y) * p->scale + 500 - p->z1;
	p->x2 = px(s.x + 1, s.y) * p->scale;
	p->z2 = tab[s.y][s.x + 1];
	p->y2 = py(s.x + 1, s.y) * p->scale + 500 - p->z2;
	return (p);
}

static	t_point	*calc_coords_2(t_point *p, t_size size, int **tab, t_size s)
{
	(void)size;
	p->x1 = px(s.x, s.y) * p->scale;
	p->z1 = tab[s.y][s.x];
	p->y1 = py(s.x, s.y) * p->scale + 500 - p->z1;
	p->x2 = px(s.x, s.y + 1) * p->scale;
	p->z2 = tab[s.y + 1][s.x];
	p->y2 = py(s.x, s.y + 1) * p->scale + 500 - p->z2;
	return (p);
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

void			draw_map(t_mlx *mlx, t_size size, int **tab)
{
	t_point *p;
	t_size	s;

	p = malloc(sizeof(*p));
	p->scale = (size.x > size.y) ? 250 / size.x : 250 / size.y;
	p->v_scale = (500 - p->scale * size.x) / highest_point(tab, size);
	s.y = -1;
	while (++(s.y) < size.y)
	{
		s.x = -1;
		while (++(s.x) < size.x - 1)
			draw_line(calc_coords(p, size, tab, s), mlx);
	}
	s.y = -1;
	while (++(s.y) < size.y - 1)
	{
		s.x = -1;
		while (++(s.x) < size.x)
			draw_line(calc_coords_2(p, size, tab, s), mlx);
	}
	free(p);
}
