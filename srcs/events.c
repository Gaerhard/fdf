/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:09:36 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/20 11:41:03 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		x_shift(int key)
{
	return ((key == 123) ? -10 : 10);
}

static int		y_shift(int key)
{
	return ((key == 125) ? 10 : -10);
}

void		redraw(t_env *e)
{
	mlx_destroy_image(e->p.mlx, e->img.ptr);
	e->img.ptr = mlx_new_image(e->p.mlx, e->m.width, e->m.height);
	e->img.data = (int*)mlx_get_data_addr(e->img.ptr, &e->img.bpp, 
			&e->img.size_l, &e->img.endian);
	draw_map(e);
}

int				mlx_close(t_env *e)
{
	int i;

	i = 0;
	free(e->p.mlx);
	free(e->p.win);
	free(e);
	exit (0);
}

int		key_press(int key, t_env *e)
{
	if (key == 53)
		mlx_close(e);
	else if (key == 257)
	{
		e->start = 0;
		e->projection = (e->projection == ISO) ? PARALLELE : ISO;
	}
	else if (key == 86 || key == 88)
		x_axis_rotation(e, key);
	else if (key == 91 || key == 87)
		y_axis_rotation(e, key);
	else if (key == 89 || key == 92)
		z_axis_rotation(e, key);
	else if (key == 123 || key == 124)
		e->move.x += x_shift(key);
	else if (key == 125 || key == 126)
		e->move.y += y_shift(key);
	redraw(e);
	return (0);
}
