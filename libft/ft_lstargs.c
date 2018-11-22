/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:05:43 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/10 13:07:53 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstargs(int ac, char **av)
{
	int		i;
	t_list	*begin_list;

	i = 0;
	begin_list = NULL;
	while (i < ac)
	{
		ft_lstfront(&begin_list, av[i], ft_strlen(av[i]));
		i++;
	}
	return (begin_list);
}
