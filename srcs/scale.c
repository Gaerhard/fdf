/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:55:54 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/19 18:29:28 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		calc_scale(t_env *e)
{
	double d_x;
	double d_y;

	e->start = 1;
	d_y = py(e->m.nc - 1, e->m.nl - 1, e) -  py(0, 0, e);
	d_x = px(e->m.nc - 1, 0, e) - px(0, e->m.nl - 1, e);
	if (d_x > d_y)
		return (e->m.width / (d_x) * 3 / 4);
	return (e->m.height / (d_y) * 3 / 4);
}

void		center_map(t_env *e)
{
	int center_x;
	int	center_y;

	center_x = e->m.scale * (px(e->m.nc - 1, 0, e) - 
			px(0, e->m.nl - 1, e)) / 2 - ft_abs(px(0, e->m.nl, e)) * e->m.scale;
	center_y = e->m.scale * (py(e->m.nc - 1, e->m.nl - 1, e) - 
			py(0, 0, e)) / 2 - ft_abs(py(0, 0, e)) * e->m.scale;
	e->move.x = e->m.width / 2 - center_x;
	e->move.y = e->m.height / 2 - center_y;
}
