/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 21:04:30 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/10 21:57:49 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# define ISO 1
# define PARALLELE 2
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
** structure contenant la matrice du premier point.
** x,y,z etant les coordonnees et c etant la couleur du point
*/

typedef struct	s_m1
{
	double			x;
	double			y;
	double			z;
	int			c;
}				t_m1;

/*
** structure contenat la matrice du deuxieme point.
** x,y,z etant les coordonnees et c etant la couleur du point
*/

typedef struct	s_m2
{
	double			x;
	double			y;
	double			z;
	int			c;
}				t_m2;

/*
** structure contant les differentes infos de la fenetre et de la map
** height et width sont respectivement la hauteur et la largeur de la fenetre
** nl et nc sont respectivement le nombre de lignes et de colonnes dans
** la map
** tab est un tableau de tableau d'int tab[i][j] avec i = coordonnee y
** j = coordonnee x et tab[i][j] = coordonnee z
** scale est l'echelle de la map, plus precisement la distance entre deux 
** coordonnees
*/

typedef struct	s_map
{
	int			nl;
	int			nc;
	int			height;
	int			width;
	int			scale;
	int			**tab;
}				t_map;

/*
** structure contenant toutes les autres structures pour y avoir acces partout
*/

typedef struct	s_env
{
	t_mlx		p;
	t_img		img;
	t_m1		v1;
	t_m2		v2;
	t_map		m;
	int			x;
	int			y;
	int			projection;
	double		sc;
	int			delta_x;
	int			delta_y;
}				t_env;

typedef struct	s_all
{
	t_mlx		*p;
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
	t_img		*img;
}				t_all;

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

t_list			*reader(char *s);
int				stoi(t_list *begin_list, int ***tab);
int				draw_line(t_env *e);
int				key_press(int key, t_env *e);
int				ft_color(t_env *e, int x, int y);
int				mlx_close(t_env *e);
void			draw_map(t_env *e);

#endif
