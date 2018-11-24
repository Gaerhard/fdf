/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:20:48 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/24 12:30:22 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**void		draw_map(t_mlx *p, int ny, int nx)
**{
**	int y;
**	int x;
**
**	y = 0;
**	while (++y < ny)
**	{
**		x = 0;
**		while (++x < nx - 1)
**			draw_line(x * (1000 / nx), y * (1000 / ny), \
**					(x + 1) * (1000 / nx), y * (1000 / ny), p);
**	}
**	y = 0;
**	while (++y < ny - 1)
**	{
**		x = 0;
**		while (++x < nx)
**			draw_line(x * (1000 / nx), y * (1000 / ny), \
**					x * (1000 / nx), (y + 1) * (1000 / ny), p);
**	}
**
**}
*/

static int		px(int x, int y)
{
	return (2 * (x + y));
}

static int		py(int x, int y)
{
	return (y - x);
}

static	void	calc_coords(t_point *p, t_size size, int **tab, t_size s)
{
	int scale;

	scale = (size.x > size.y) ? 250 / size.x : 250 / size.y;
	p->x1 = px(s.x, s.y) * scale;
	p->z1 = tab[s.y][s.x];
	p->y1 = py(s.x, s.y) * scale + 500 - p->z1;
	p->x2 = px(s.x + 1, s.y) * scale;
	p->z2 = tab[s.y][s.x + 1];
	p->y2 = py(s.x + 1, s.y) * scale + 500 - p->z2;
}

static	void	calc_coords_2(t_point *p, t_size size, int **tab, t_size s)
{
	int scale;

	scale = (size.x > size.y) ? 250 / size.x : 250 / size.y;
	p->x1 = px(s.x, s.y) * scale;
	p->z1 = tab[s.y][s.x];
	p->y1 = py(s.x, s.y) * scale + 500 - p->z1;
	p->x2 = px(s.x, s.y + 1) * scale;
	p->z2 = tab[s.y + 1][s.x];
	p->y2 = py(s.x, s.y + 1) * scale + 500 - p->z2;
}

/*
**	n = (ny > nx) ? ((1000 / m - m) / 4) * m : 250 / nx;
*/

void			draw_map(t_mlx *mlx, t_size size, int **tab)
{
	t_point *p;
	t_size	s;

	p = malloc(sizeof(*p));
	s.y = -1;
	while (++(s.y) < size.y)
	{
		s.x = -1;
		while (++(s.x) < size.x - 1)
		{
			calc_coords(p, size, tab, s);
			draw_line(p, mlx);
		}
	}
	s.y = -1;
	while (++(s.y) < size.y - 1)
	{
		s.x = -1;
		while (++(s.x) < size.x)
		{
			calc_coords_2(p, size, tab, s);
			draw_line(p, mlx);
		}
	}
	free(p);
}
