/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:34:15 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/24 19:22:46 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void	clean_tab(int ***tab, int l)
{
	int i;

	i = -1;
	while (++i <= l)
		free(tab[0][i]);
	free(tab[0]);
}
*/
int		key_press(int key, t_mlx *p)
{
	(void)p;
	if (key == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit(0);
	}
	return (0);
}

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
//	clean_tab(&tab, g.y);
	mlx_key_hook(p->win_ptr, key_press, p);
	mlx_loop(p->mlx_ptr);
	return (0);
}
