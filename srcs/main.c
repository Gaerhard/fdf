/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:34:15 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/08 17:20:13 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**static void	clean_tab(int ***tab, int l)
**{
**	int i;
**
**	i = -1;
**	while (++i <= l)
**		free(tab[0][i]);
**	free(tab[0]);
**}
*/

int		init(t_env *e)
{
//	void	*tmp;

	e->m.width = (e->m.nc * 4 + 50 > 1000) ? e->m.nc * 4 + 50 : 1000;
	e->m.height = (e->m.nl * 2 > 1000) ? (e->m.nl * 2) : 1000;
	e->sc = 1.0;
	if (!(e->p.mlx = mlx_init()))
		return (-1);
	if (!(e->p.win = mlx_new_window(e->p.mlx, e->m.width , e->m.height, "fdf")))
		return (-1);
	e->img.ptr = mlx_new_image(e->p.mlx, e->m.width, e->m.height);
	e->img.data = (int*)mlx_get_data_addr(e->img.ptr, &e->img.bpp, &e->img.size_l, &e->img.endian);
	draw_map(e);
	mlx_hook(e->p.win, 2, 0, key_press, e);
	mlx_hook(e->p.win, 17, 0, mlx_close, e);
	mlx_loop(e->p.mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_env	*e;

	if (argc != 2)
		return (ft_print_return("Wrong number of arguments", 2));
	e = malloc(sizeof(*e) * 1);
	if (!(lst = reader(argv[1])))
		return (ft_print_return("Failed to read file", 2));
	else
	{
		if ((e->m.nl = ft_lstlength(lst)) <= 0)
			return (ft_print_return("Invalid file", 2));
		if (!(e->m.tab = malloc(sizeof(int*) * e->m.nl)))
			return (ft_print_return("Failed to malloc correct size", 2));
		if ((e->m.nc = stoi(lst, &(e->m.tab))) == 0)
			return (ft_print_return("Invalid file", 2));
	}
	if (init (e) < 0)
		return (0);
	return (0);
}
