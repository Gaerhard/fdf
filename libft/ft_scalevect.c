/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalevect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:23:31 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/10 15:25:33 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_scalevect(t_vect *vector, int scale)
{
	vector->x = vector->x * scale;
	vector->y = vector->y * scale;
	vector->z = vector->z * scale;
}
