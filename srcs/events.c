/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:09:36 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/28 20:09:16 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		calc_new_coords(int v, t_all *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->n_line)
	{
		j = -1;
		while (++j < p->n_col)
		{
	//		p->tab[i][j] += (p->tab[i][j] >= 1 && v > 0) ? 0 : v;
			p->tab[i][j] += (p->tab[i][j] == 0) ? 0 : v;
			if (p->tab[i][j] == 1)
				p->tab[i][j]++;
		}
	}
	mlx_clear_window(p->mlx, p->win);
	draw_map(p);
}

int				mlx_close(t_all *p)
{
	free(p);
	exit(0);
}

int		key_press(int key, t_all *p)
{
	int v;

	v = 0;
	if (key == 53)
		exit (0);
	if (key == 78)
	{
		v--;
		calc_new_coords(v, p);
	}
	if (key == 69)
	{
		v++;
		calc_new_coords(v, p);
	}
	return (0);
}
