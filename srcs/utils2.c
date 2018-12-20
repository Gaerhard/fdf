/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:39:58 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/20 19:42:40 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_map(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < e->m.nl)
	{
		x = -1;
		while (++x < e->m.nc)
		{
			TABZ = TABZ * e->move.sc;
		}
	}
}

double	get_vertical_scale(t_env *e)
{
	t_lim lim;

	lim = get_limits(e);
	return ((double)e->m.nl / ((double)lim.z_max * 10));
}

void	set_levels(t_env *e, int x, int y, t_lim lim)
{
	(void)lim;
	if (TABZ <= 0)
		TABC = 0x00C3E1FF;
	if (TABZ > 0 && TABZ <= e->delta_x / 14)
		TABC = 0x00344623;
	else if (TABZ > e->delta_x / 14 && TABZ <= 2 * e->delta_x / 14)
		TABC = 0x007E9F5D;
	else if (TABZ > 2 * e->delta_x / 14 && TABZ <= 3 * e->delta_x / 14)
		TABC = 0x00B7CAA4;
	else if (TABZ > 3 * e->delta_x / 14 && TABZ <= 4 * e->delta_x / 14)
		TABC = 0x00CBAC83;
	else if (TABZ > 4 * e->delta_x / 14 && TABZ <= 5 * e->delta_x / 14)
		TABC = 0x0075552D;
	else if (TABZ > 5 * e->delta_x / 14 && TABZ <= 6 * e->delta_x / 14)
		TABC = 0x00583405;
	else if (TABZ > 6 * e->delta_x / 14)
		TABC = 0x00FFFFFF;
}
