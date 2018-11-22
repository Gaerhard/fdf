/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:38:05 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/10 11:44:32 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *n_lst;
	t_list *tmp;
	t_list *begin_lst;

	if (!(n_lst = malloc(sizeof(t_list))))
		return (NULL);
	n_lst = f(lst);
	begin_lst = n_lst;
	tmp = n_lst;
	n_lst->next = NULL;
	n_lst = n_lst->next;
	lst = lst->next;
	while (lst)
	{
		if (!(n_lst = malloc(sizeof(t_list))))
			return (NULL);
		n_lst = f(lst);
		tmp->next = n_lst;
		n_lst->next = NULL;
		tmp = n_lst;
		lst = lst->next;
	}
	return (begin_lst);
}
