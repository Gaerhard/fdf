/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:20:48 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/28 16:46:16 by gaerhard         ###   ########.fr       */
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

static	t_all	*calc_coords(t_all *p)
{
	p->x1 = px(p->x, p->y) * p->scale;
	p->z1 = p->tab[p->y][p->x];
	p->y1 = py(p->x, p->y) * p->scale + p->height / 2 - p->z1;
	p->x2 = px(p->x + 1, p->y) * p->scale;
	p->z2 = p->tab[p->y][p->x + 1];
	p->y2 = py(p->x + 1, p->y) * p->scale + p->height / 2 - p->z2;
	if (p->z1 <= 0)
		p->color1 = 0x00009FFF - ft_abs(p->z1);
	else if (p->z1 >= 1 && p->z1 <= 40)
		p->color1 = 0x00009F40 + (p->z1 * 0x00050000);
	else if (p->z1 >= 41 && p->z1 <= 70)
		p->color1 = 0x00999999 + p->z1 * 0x00111111;
	else if (p->z1 >= 71)
		p->color1 = 0x00FFFFFF;
	if (p->z2 <= 0)
		p->color2 = 0x00009FFF - ft_abs(p->z2);
	else if (p->z2 >= 1 && p->z2 <= 40)
		p->color2 = 0x00009F40 + (p->z2 * 0x00050000);
	else if (p->z2 >= 41 && p->z2 <= 70)
		p->color2 = 0x00999999 + p->z2 * 0x00111111;
	else if(p->z2 > 70)	
		p->color2 = 0x00FFFFFF;
	return (p);
}

static	t_all	*calc_coords_2(t_all *p)
{
	p->x1 = px(p->x, p->y) * p->scale;
	p->z1 = p->tab[p->y][p->x];
	p->y1 = py(p->x, p->y) * p->scale + p->height / 2 - p->z1;
	p->x2 = px(p->x, p->y + 1) * p->scale;
	p->z2 = p->tab[p->y + 1][p->x];
	p->y2 = py(p->x, p->y + 1) * p->scale + p->height / 2 - p->z2;
	if (p->z1 <= 0)
		p->color1 = 0x00009FFF - ft_abs(p->z1);
	else if (p->z1 >= 1 && p->z1 <= 40)
		p->color1 = 0x00009F40 + (p->z1 * 0x00050000);
	else if (p->z1 >= 41 && p->z1 <= 70)
		p->color1 = 0x00999999 + p->z1 * 0x00111111;
	else if (p->z1 >= 71)
		p->color1 = 0x00FFFFFF;
	if (p->z2 <= 0)
		p->color2 = 0x00009FFF - ft_abs(p->z2);
	else if (p->z2 >= 1 && p->z2 <= 40)
		p->color2 = 0x00009F40 + (p->z2 * 0x00050000);
	else if (p->z2 >= 41 && p->z2 <= 70)
		p->color2 = 0x00999999 + p->z2 * 0x00111111;
	else if(p->z2 > 70)	
		p->color2 = 0x00FFFFFF;
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

void			draw_map(t_all *p)
{
	p->scale = (p->n_col > p->n_line) ?
		(p->length / 4) / p->n_col : (p->length / 4) / p->n_line;
	p->scale = (p->scale == 0) ? 1 : p->scale;
	p->y = -1;
	while (++(p->y) < p->n_line)
	{
		p->x = -1;
		while (++(p->x) < p->n_col - 1)
			draw_line(calc_coords(p));
	}
	p->y = -1;
	while (++(p->y) < p->n_line - 1)
	{
		p->x = -1;
		while (++(p->x) < p->n_col)
			draw_line(calc_coords_2(p));
	}
}
