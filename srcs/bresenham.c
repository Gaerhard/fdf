/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:21:08 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/08 15:32:58 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	vertical_slope(t_env *e, t_incr incr)
{
	int		x;
	int		y;
	int		i;

	x = e->v1.x;
	i = -1;
	y = e->v1.y;
	incr.error = e->delta_y;
	while (++i < e->delta_y)
	{
		y += incr.yincr;
		incr.error += e->delta_x * 2;
		x += (incr.error > e->delta_y ? incr.xincr : 0);
		incr.error -= (incr.error > e->delta_y ? e->delta_y * 2 : 0);
		if (y * e->m.width + x >= 0 &&
				y * e->m.width + x < e->m.width * e->m.height)
			e->img.data[y * e->m.width + x] = ft_color(e, x, y);
	}
	return (1);
}

static int	horizontal_slope(t_env *e, t_incr incr)
{
	int		x;
	int		y;
	int		i;

	x = e->v1.x;
	i = -1;
	y = e->v1.y;
	incr.error = e->delta_x;
	while (++i < e->delta_x)
	{
		x += incr.xincr;
		incr.error += e->delta_y * 2;
		y += (incr.error > e->delta_x ? incr.yincr : 0);
		incr.error -= (incr.error > e->delta_x ? (e->delta_x * 2) : 0);
		if (y * e->m.width + x >= 0 &&
				y * e->m.width + x < e->m.width * e->m.height)
			e->img.data[y * e->m.width + x] = ft_color(e, x, y);
	}
	return (1);
}

int			draw_line(t_env *e)
{
	t_incr	incr;

	incr.xincr = (e->v1.x < e->v2.x ? 1 : -1);
	incr.yincr = (e->v1.y < e->v2.y ? 1 : -1);
	e->delta_x = ft_abs(e->v2.x - e->v1.x);
	e->delta_y = ft_abs(e->v2.y - e->v1.y);
	if (e->delta_x < e->delta_y)
		return (vertical_slope(e, incr));
	return (horizontal_slope(e, incr));
}
