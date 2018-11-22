/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfront.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:02:02 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/10 13:03:32 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstfront(t_list **begin_list, void *data, size_t size)
{
	t_list	*n_list;

	n_list = ft_lstnew(data, size);
	if (n_list)
	{
		n_list->next = *begin_list;
		*begin_list = n_list;
	}
}
