/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sumvect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:26:40 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/10 15:29:36 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect		ft_sumvect(const t_vect v1, const t_vect v2)
{
	t_vect v_sum;

	v_sum.x = v1.x + v2.x;
	v_sum.y = v1.y + v2.y;
	v_sum.z = v1.z + v2.z;
	return (v_sum);
}
