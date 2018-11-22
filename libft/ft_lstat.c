/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:57:23 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/10 12:57:31 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*tmp_list;

	i = 0;
	tmp_list = begin_list;
	while (tmp_list)
	{
		if (i == nbr)
			return (tmp_list);
		tmp_list = tmp_list->next;
		i++;
	}
	return (NULL);
}
