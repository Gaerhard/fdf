/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:20:48 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/28 11:35:18 by gaerhard         ###   ########.fr       */
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

static	t_point	*calc_coords(t_point *p, t_size size, int **tab, t_size s)
{
	(void)size;
	p->x1 = px(s.x, s.y) * p->scale;
	p->z1 = tab[s.y][s.x];
	p->y1 = py(s.x, s.y) * p->scale + size.height / 2 - p->z1;
	p->x2 = px(s.x + 1, s.y) * p->scale;
	p->z2 = tab[s.y][s.x + 1];
	p->y2 = py(s.x + 1, s.y) * p->scale + size.height / 2 - p->z2;
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

static	t_point	*calc_coords_2(t_point *p, t_size size, int **tab, t_size s)
{
	(void)size;
	p->x1 = px(s.x, s.y) * p->scale;
	p->z1 = tab[s.y][s.x];
	p->y1 = py(s.x, s.y) * p->scale + size.height / 2 - p->z1;
	p->x2 = px(s.x, s.y + 1) * p->scale;
	p->z2 = tab[s.y + 1][s.x];
	p->y2 = py(s.x, s.y + 1) * p->scale + size.height / 2 - p->z2;
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

void			draw_map(t_mlx *mlx, t_size size, int **tab)
{
	t_point *p;
	t_size	s;

	p = malloc(sizeof(*p));
	p->scale = (size.x > size.y) ? (size.length / 4) / size.x : (size.length / 4) / size.y;
	p->scale = (p->scale == 0) ? 1 : p->scale;
	s.y = -1;
	while (++(s.y) < size.y)
	{
		s.x = -1;
		while (++(s.x) < size.x - 1)
			draw_line(calc_coords(p, size, tab, s), mlx);
	//	ft_putnbr(calc_coords(p, size, tab, s)->x1);
	//	ft_putchar(' ');
	//	ft_putnbr(calc_coords(p, size, tab, s)->x2);
	//	ft_putchar(' ');
	//	ft_putnbr(calc_coords(p, size, tab, s)->y1);
	//	ft_putchar(' ');
	//	ft_putnbr(calc_coords(p, size, tab, s)->y2);
	//	ft_putchar(' ');
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
