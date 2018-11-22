/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prodvect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:46:29 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/12 14:29:34 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect		ft_prodvect(const t_vect v1, const t_vect v2)
{
	t_vect	vprod;

	vprod.x = v1.y * v2.z - v1.z * v2.y;
	vprod.y = v1.z * v2.x - v1.x * v2.z;
	vprod.z = v1.x * v2.y - v1.y * v2.x;
	return (vprod);
}
