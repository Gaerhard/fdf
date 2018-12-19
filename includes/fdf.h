/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 21:04:30 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/19 18:39:05 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# define ISO 1
# define PARALLELE 2
# define TABX e->m.tab[y][x].x
# define TABXX e->m.tab[y][x + 1].x
# define TABXY e->m.tab[y + 1][x].x
# define TABY e->m.tab[y][x].y
# define TABYX e->m.tab[y][x + 1].y
# define TABYY e->m.tab[y + 1][x].y
# define TABZ e->m.tab[y][x].z
# define TABZX e->m.tab[y][x + 1].z
# define TABZY e->m.tab[y + 1][x].z
# define TABC e->m.tab[y][x].c
/*
** structure contenant les donnes de l'image mlx utilisee
*/

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

/*
** structure principale de la mlx
*/

typedef struct	s_mlx
{
	void		*win;
	void		*mlx;
}				t_mlx;

/*
** structure contenat la matrice des points a tracer et relier
** x,y,z etant les coordonnees et c etant la couleur du point
*/

typedef struct	s_m
{
	double		x;
	double		y;
	double		z;
	int			c;
}				t_m;

/*
** structure contant les differentes infos de la fenetre et de la map
** height et width sont respectivement la hauteur et la largeur de la fenetre
** nl et nc sont respectivement le nombre de lignes et de colonnes dans
** la map
** tab est un tableau de tableau de matrices contenat les coordonnees despoints
** scale est l'echelle de la map, plus precisement la distance entre deux 
** coordonnees
*/

typedef struct	s_map
{
	int			nl;
	int			nc;
	int			height;
	int			width;
	float		scale;
	t_m			**tab;
}				t_map;

/*
** structure contenant la valeur du delpacement en x et y de la map
** sc contient l'echelle en z (manipulee avec + et -)
*/

typedef struct	s_move
{
	double		sc;
	int			x;
	int			y;
}				t_move;

/*
** structure contenant toutes les autres structures pour y avoir acces partout
*/

typedef struct	s_env
{
	t_mlx		p;
	t_img		img;
	t_m			v1;
	t_m			v2;
	t_map		m;
	t_move		move;
	int			projection;
	int			start;
	int			delta_x;
	int			delta_y;
}				t_env;

/*
** structure utilisee lors du trace de ligne dans l'algo de bresenham pour
** calculer l'incrementation de x ou y, positive ou negative et quand 
** incrementer
*/

typedef struct	s_incr
{
	int			error;
	int			xincr;
	int			yincr;
}				t_incr;

typedef struct	s_lim
{
	int			z_max;
	int			z_min;
}				t_lim;

t_list			*reader(char *s);
double			px(double x, double y, t_env *e);
double			py(double x, double y, t_env *e);
double			get_vertical_scale(t_env *e);
int				stoi(t_list *begin_list, t_m **tab);
int				draw_line(t_env *e);
int				key_press(int key, t_env *e);
int				mouse_press(int button, int x, int y, t_env *e);
int				ft_color(t_env *e, int x, int y);
int				mlx_close(t_env *e);
void			set_colors(t_env *e);
float			calc_scale(t_env *e);
void			scale_map(t_env *e);
void			draw_map(t_env *e);
void			x_axis_rotation(t_env *e, int key);
void			y_axis_rotation(t_env *e, int key);
void			z_axis_rotation(t_env *e, int key);
void			set_levels(t_env *e, int x, int y);
void			center_map(t_env *e);
void			redraw(t_env *e);
t_lim			get_limits(t_env *e);

#endif
