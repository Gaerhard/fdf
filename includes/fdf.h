/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 21:04:30 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/28 20:09:47 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"

typedef struct	s_all
{
	void		*win;
	void		*mlx;
	int			**tab;
	int			n_line;
	int			n_col;
	int			height;
	int			length;
	int			x;
	int			y;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			z1;
	int			z2;
	int			color1;
	int			color2;
	int			scale;
	int			v;
}				t_all;
/*
typedef struct	s_mlx
{
	void		*win_ptr;
	void		*mlx_ptr;
}				t_mlx;
*/
/*
** structure contenant la taille de la fenetre, x = nb colonnes
** y = nb lignes, height = hauteur de la fenetre et length sa longueur
*/
/*
typedef struct	s_size
{
	int			x;
	int			y;
	int			height;
	int			length;
}				t_size;
*/
/*
** structure principale contenant les coordonnees x,y,z des points a relier
*/
/*
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
*/
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
int				draw_line(t_all *p);
int				key_press(int key, t_all *p);
int				ft_color(t_all *p, int x, int y);
int				mlx_close(t_all *p);
void			draw_map(t_all *p);

#endif
