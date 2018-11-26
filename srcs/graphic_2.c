/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:55:25 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/26 19:24:19 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		highest_point(int **tab, t_size size)
{
	int i;
	int j;
	int res;

	i = -1;
	res = 0;
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
		{
			if (tab[i][j] > res)
				res = tab[i][j];
		}
	}
	return (res);
}
