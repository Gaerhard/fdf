/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:09:36 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/08 17:58:06 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		calc_new_coords(double v, t_env *e)
{
/*	int i;
	int j;

	i = -1;
	while (++i < e->m.nl)
	{
		j = -1;
		while (++j < e->m.nc)
		{
			e->m.tab[i][j] += (e->m.tab[i][j] <= 0) ? 0 : v;
			if (e->m.tab[i][j] == 1)
				e->m.tab[i][j]++;
		}
	}*/
	e->sc += v;
	mlx_clear_window(e->p.mlx, e->p.win);
	mlx_destroy_image(e->p.mlx, e->img.ptr);
	e->img.ptr = mlx_new_image(e->p.mlx, e->m.width, e->m.height);
	ft_bzero(e->img.data, e->m.width * e->m.height);
	draw_map(e);
}

int				mlx_close(t_env *e)
{
	int i;

	i = 0;
	free(e->p.mlx);
	free(e->p.win);
/*	while (i < p->height)
	{
		free(p->tab[i]);
		i++;
	}
	free(p->tab);*/
	free(e);
	exit (0);
}

int		key_press(int key, t_env *e)
{
	double v;

	v = 0.0;
	if (key == 53)
		mlx_close(e);
	if (key == 78)
	{
		v -= 0.1;
		calc_new_coords(v, e);
	}
	if (key == 69)
	{
		v += 0.1;
		calc_new_coords(v, e);
	}
	return (0);
}
