/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:21:08 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/24 12:38:28 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_line_y(t_point *p, t_mlx *mlx)
{
	t_incr	incr;
	int		error;
	int		x;
	int		y;
	int		i;

	incr.xincr = (p->x1 < p->x2 ? 1 : -1);
	incr.yincr = (p->y1 < p->y2 ? 1 : -1);
	x = p->x1;
	i = -1;
	y = p->y1;
	error = ft_abs(p->y2 - p->y1);
	while (++i < ft_abs(p->y2 - p->y1))
	{
		y += incr.yincr;
		error += ft_abs(p->x2 - p->x1) * 2;
		x += (error > ft_abs(p->y2 - p->y1) ? incr.xincr : 0);
		error -= (error > ft_abs(p->y2 - p->y1) ?
				(ft_abs(p->y2 - p->y1) * 2) : 0);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x00FFFFFF);
	}
	return (1);
}

int			draw_line(t_point *p, t_mlx *mlx)
{
	t_incr	incr;
	int		error;
	int		x;
	int		y;
	int		i;

	incr.xincr = (p->x1 < p->x2 ? 1 : -1);
	incr.yincr = (p->y1 < p->y2 ? 1 : -1);
	x = p->x1;
	i = -1;
	y = p->y1;
	if (ft_abs(p->x2 - p->x1) < ft_abs(p->y2 - p->y1))
		return (draw_line_y(p, mlx));
	error = ft_abs(p->x2 - p->x1);
	while (++i < ft_abs(p->x2 - p->x1))
	{
		x += incr.xincr;
		error += ft_abs(p->y2 - p->y1) * 2;
		y += (error > ft_abs(p->x2 - p->x1) ? incr.yincr : 0);
		error -= (error > ft_abs(p->x2 - p->x1) ?
				(ft_abs(p->x2 - p->x1) * 2) : 0);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x00FFFFFF);
	}
	return (1);
}
