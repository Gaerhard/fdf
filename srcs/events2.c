/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:32:15 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/19 18:41:58 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 4)
		e->m.scale += e->m.scale / 10;
	else if (button == 5)
		e->m.scale -= e->m.scale / 10;
	redraw(e);
	return (0);
}
