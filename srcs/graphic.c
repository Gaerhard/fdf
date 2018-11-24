/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:20:48 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/24 11:42:46 by gaerhard         ###   ########.fr       */
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

static int	px(int x, int y)
{
	return (2 * (x + y));
}

static int	py(int x, int y)
{
	return (y - x);
}

/*
**	n = (ny > nx) ? ((1000 / m - m) / 4) * m : 250 / nx;
*/

void		draw_map(t_mlx *p, int ny, int nx, int **tab)
{
	int y;
	int x;
	int m;
	int scale;

	y = -1;
	m = (nx > ny) ? nx : ny;
	scale = 250 / m;
	while (++y < ny)
	{
		x = -1;
		while (++x < nx - 1)
			draw_line(px(x, y) * scale, py(x, y) * scale + 500 - tab[y][x],\
				px(x + 1, y) * scale, py(x + 1, y) * scale + 500 - tab[y][x + 1], p);
	}
	y = -1;
	while (++y < ny - 1)
	{
		x = -1;
		while (++x < nx)
			draw_line(px(x, y) * scale, py(x, y) * scale + 500 - tab[y][x],\
				px(x, y + 1) * scale, py(x, y + 1) * scale + 500 - tab[y + 1][x], p);
	}
}
