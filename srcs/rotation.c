/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:25:01 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/19 16:09:14 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	translation(t_env *e, int tx, int ty)
{
	int x;
	int y;

	y = -1;
	while (++y < e->m.nl)
	{
		x = -1;
		while (++x < e->m.nc)
		{
			TABX += tx;
			TABY += ty;
		}
	}
}

void	x_axis_rotation(t_env *e, int key)
{
	int		x;
	int		y;
	double	angle;
	double	tmp;

	if (key == 88)
		angle = 3.141592 / 20;
	else
		angle = -3.141592 / 20;
	translation(e, -e->m.nc / 2, -e->m.nl / 2);
	y = -1;
	while (++y < e->m.nl)
	{
		x = -1;
		while (++x < e->m.nc)
		{
			tmp = TABY;
			TABY = TABY * cos(angle) + TABZ * sin(angle);
			TABZ = -tmp * sin(angle) + TABZ * cos(angle);
		}
	}
	translation(e, e->m.nc / 2, e->m.nl / 2);
}

void	y_axis_rotation(t_env *e, int key)
{
	int		x;
	int		y;
	double	angle;
	double	tmp;

	if (key == 91)
		angle = 3.141592 / 20;
	else
		angle = -3.141592 / 20;
	translation(e, -e->m.nc / 2, -e->m.nl / 2);
	y = -1;
	while (++y < e->m.nl)
	{
		x = -1;
		while (++x < e->m.nc)
		{
			tmp = TABX;
			TABX = TABX * cos(angle) + TABZ * sin(angle);
			TABZ = -tmp * sin(angle) + TABZ * cos(angle);
		}
	}
	translation(e, e->m.nc / 2, e->m.nl / 2);
}

void	z_axis_rotation(t_env *e, int key)
{
	int		x;
	int		y;
	double	angle;
	double	tmp;

	if (key == 92)
		angle = 3.141592 / 20;
	else
		angle = -3.141592 / 20;
	translation(e, -e->m.nc / 2, -e->m.nl / 2);
	y = -1;
	while (++y < e->m.nl)
	{
		x = -1;
		while (++x < e->m.nc)
		{
			tmp = TABX;
			TABX = TABX * cos(angle) + TABY * sin(angle);
			TABY = -tmp * sin(angle) + TABY * cos(angle);
		}
	}
	translation(e, e->m.nc / 2, e->m.nl / 2);
}
