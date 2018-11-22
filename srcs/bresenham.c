/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:21:08 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/22 18:56:46 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_y(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
	t_incr incr;
	int error;
	int x;
	int y;
	int i;

	incr.xincr = (x1 < x2 ? 1 : -1);
	incr.yincr = (y1 < y2 ? 1 : -1);
	x = x1;
	i = -1;
	y = y1;
	error = ft_abs(y2 - y1);
	while (++i < ft_abs(y2 - y1))
	{
		y += incr.yincr;
		error += ft_abs(x2 - x1) * 2;
		x += (error > ft_abs(y2 - y1) ? incr.xincr : 0);
		error -= (error > ft_abs(y2 - y1) ? (ft_abs(y2 - y1) * 2) : 0);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x00FFFFFF);
	}
}

void	draw_line_x(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
	t_incr incr;
	int error;
	int x;
	int y;
	int i;

	incr.xincr = (x1 < x2 ? 1 : -1);
	incr.yincr = (y1 < y2 ? 1 : -1);
	x = x1;
	i = -1;
	y = y1;
	if (ft_abs(x2 - x1) < ft_abs(y2 - y1))
		draw_line_y(x1, y1, x2, y2, mlx);
	else
	{
		error = ft_abs(x2 - x1);
		while (++i < ft_abs(x2 - x1))
		{
			x += incr.xincr;
			error += ft_abs(y2 - y1) * 2;
			y += (error > ft_abs(x2 - x1) ? incr.yincr : 0);
			error -= (error > ft_abs(x2 - x1) ? (ft_abs(x2 - x1) * 2) : 0);
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x00FFFFFF);
		}
	}
}
