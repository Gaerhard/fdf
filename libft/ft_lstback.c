/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:22:51 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/21 15:19:56 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstback(t_list **begin_list, void *data, size_t size)
{
	t_list *list;

	list  = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(data, size);
	}
	else
		*begin_list = ft_lstnew(data, size);
}
