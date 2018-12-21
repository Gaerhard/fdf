/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:34:15 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/21 12:37:21 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**void	__attribute__((destructor)) end()
**{
**	printf("destructor loop");
**	while (1);
**}
*/

int		init(t_env *e)
{
	e->m.width = 1920;
	e->m.height = 1280;
	e->move.sc = get_vertical_scale(e);
	scale_map(e);
	set_colors(e);
	e->start = 0;
	e->move.x = 0;
	e->move.y = 0;
	e->projection = ISO;
	if (!(e->p.mlx = mlx_init()))
		return (-1);
	if (!(e->p.win = mlx_new_window(e->p.mlx, e->m.width, e->m.height, "fdf")))
		return (-1);
	e->img.ptr = mlx_new_image(e->p.mlx, e->m.width, e->m.height);
	e->img.data = (int*)mlx_get_data_addr(e->img.ptr, &e->img.bpp,
			&e->img.size_l, &e->img.endian);
	draw_map(e);
	mlx_hook(e->p.win, 2, 0, key_press, e);
	mlx_hook(e->p.win, 17, 0, mlx_close, e);
	mlx_hook(e->p.win, 4, 0, mouse_press, e);
	mlx_loop(e->p.mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_env	*e;

	if (argc != 2)
		return (ft_print_return("Wrong number of arguments", 2));
	if (!(e = malloc(sizeof(*e) * 1)))
		return (ft_print_return("Failed to allocate memory", 2));
	if (!(lst = reader(argv[1])))
		return (ft_free_return("Failed to read file", 2, e));
	else
	{
		if ((e->m.nl = ft_lstlength(lst)) <= 0)
			return (ft_free_return("Invalid file", 2, e));
		if (!(e->m.tab = malloc(sizeof(t_m*) * e->m.nl)))
			return (ft_free_return("Failed to malloc correct size", 2, e));
		if ((e->m.nc = stoi(lst, (e->m.tab))) == 0 ||
				(e->m.nc <= 1 && e->m.nl <= 1))
			return (ft_free_return("Invalid file", 2, e));
	}
	if (init(e) < 0)
		return (ft_free_return("Failed to init mlx", 2, e));
	return (0);
}
