/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:56:51 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/10 12:57:10 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *b_list, void *to_find, int (*cmp)())
{
	t_list *ptr_list;

	if (!b_list)
		return (NULL);
	ptr_list = b_list;
	while (ptr_list)
	{
		if (cmp(to_find, ptr_list->content) == 0)
			return (ptr_list);
		ptr_list = ptr_list->next;
	}
	return (NULL);
}
