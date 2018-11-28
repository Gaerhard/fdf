/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 21:04:30 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/28 13:46:29 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"

typedef struct	s_mlx
{
	void		*win_ptr;
	void		*mlx_ptr;
}				t_mlx;

/*
** structure contenant la taille de la fenetre, x = nb colonnes
** y = nb lignes, height = hauteur de la fenetre et length sa longueur
*/

typedef struct	s_size
{
	int			x;
	int			y;
	int			height;
	int			length;
}				t_size;

/*
** structure principale contenant les coordonnees x,y,z des points a relier
*/
typedef struct	s_point
{
	int			x1;
	int			y1;
	int			z1;
	int			x2;
	int			y2;
	int			z2;
	int			scale;
	int			color1;
	int			color2;
}				t_point;

/*
** structure utilisee lors du trace de ligne dans l'algo de bresenham
*/

typedef struct	s_incr
{
	int			error;
	int			xincr;
	int			yincr;
}				t_incr;

t_list			*reader(char *s);
int				stoi(t_list *begin_list, int ***tab);
int				draw_line(t_point *p, t_mlx *mlx);
int				key_press(int key, t_mlx *p);
int				ft_color(t_point *p, int x, int y);
int				highest_point(int **tab, t_size size);
void			draw_map(t_mlx *p, t_size size, int **tab);

#endif
