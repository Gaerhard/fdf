/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:34:15 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/24 12:29:41 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		**tab;
	t_list	*lst;
	t_size	g;
	t_mlx	*p;

	p = malloc(sizeof(*p) * 1);
	if (argc != 2)
		return (ft_print_return("Wrong number of arguments", 2));
	if (!(lst = reader(argv[1])))
		return (ft_print_return("Failed to read file", 2));
	else
	{
		if ((g.y = ft_lstlength(lst)) <= 0)
			return (ft_print_return("Invalid file", 2));
		if (!(tab = malloc(sizeof(int*) * g.y)))
			return (ft_print_return("Failed to malloc correct size", 2));
		if ((g.x = stoi(lst, &tab)) == 0)
			return (ft_print_return("Invalid file", 2));
	}
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, 1000, 1000, "fdf");
	draw_map(p, g, tab);
	mlx_loop(p->mlx_ptr);
	return (0);
}
