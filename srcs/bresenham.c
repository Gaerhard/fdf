/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:21:08 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/28 16:50:02 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		draw_line_y(t_all *p)
{
	t_incr	incr;
	int		x;
	int		y;
	int		i;

	incr.xincr = (p->x1 < p->x2 ? 1 : -1);
	incr.yincr = (p->y1 < p->y2 ? 1 : -1);
	x = p->x1;
	i = -1;
	y = p->y1;
	incr.error = ft_abs(p->y2 - p->y1);
	while (++i < ft_abs(p->y2 - p->y1))
	{
		y += incr.yincr;
		incr.error += ft_abs(p->x2 - p->x1) * 2;
		x += (incr.error > ft_abs(p->y2 - p->y1) ? incr.xincr : 0);
		incr.error -= (incr.error > ft_abs(p->y2 - p->y1) ?
				(ft_abs(p->y2 - p->y1) * 2) : 0);
		mlx_pixel_put(p->mlx, p->win, x, y, ft_color(p, x, y));
	}
	return (1);
}

int				draw_line(t_all *p)
{
	t_incr	incr;
	int		x;
	int		y;
	int		i;

	incr.xincr = (p->x1 < p->x2 ? 1 : -1);
	incr.yincr = (p->y1 < p->y2 ? 1 : -1);
	x = p->x1;
	i = -1;
	y = p->y1;
	if (ft_abs(p->x2 - p->x1) < ft_abs(p->y2 - p->y1))
		return (draw_line_y(p));
	incr.error = ft_abs(p->x2 - p->x1);
	while (++i < ft_abs(p->x2 - p->x1))
	{
		x += incr.xincr;
		incr.error += ft_abs(p->y2 - p->y1) * 2;
		y += (incr.error > ft_abs(p->x2 - p->x1) ? incr.yincr : 0);
		incr.error -= (incr.error > ft_abs(p->x2 - p->x1) ?
				(ft_abs(p->x2 - p->x1) * 2) : 0);
		mlx_pixel_put(p->mlx, p->win, x, y, ft_color(p, x, y));
	}
	return (1);
}
