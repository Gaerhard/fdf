/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:34:15 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/28 20:13:08 by gaerhard         ###   ########.fr       */
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

int		init(t_all *p)
{
	p->length = (p->n_col * 4 + 50 > 1000) ? p->n_col * 4 + 50 : 1000;
	p->height = (p->n_line * 2 > 1000) ? (p->n_line * 2) : 1000;
	if (!(p->mlx = mlx_init()))
		return (-1);
	if (!(p->win = mlx_new_window(p->mlx, p->length , p->height, "fdf")))
		return (-1);
	draw_map(p);
	mlx_hook(p->win, 2, 0, key_press, p);
	mlx_hook(p->win, 17, 0, mlx_close, p);
	mlx_loop(p->mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_all	*p;

	p = malloc(sizeof(*p) * 1);
	if (argc != 2)
		return (ft_print_return("Wrong number of arguments", 2));
	if (!(lst = reader(argv[1])))
		return (ft_print_return("Failed to read file", 2));
	else
	{
		if ((p->n_line = ft_lstlength(lst)) <= 0)
			return (ft_print_return("Invalid file", 2));
		if (!(p->tab = malloc(sizeof(int*) * p->n_line)))
			return (ft_print_return("Failed to malloc correct size", 2));
		if ((p->n_col = stoi(lst, &(p->tab))) == 0)
			return (ft_print_return("Invalid file", 2));
	}
	if (init (p) < 0)
		return (0);
	return (0);
}
