/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 21:04:30 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/24 12:37:12 by gaerhard         ###   ########.fr       */
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

typedef struct	s_size
{
	int			x;
	int			y;
}				t_size;

typedef struct	s_point
{
	int			x1;
	int			y1;
	int			z1;
	int			x2;
	int			y2;
	int			z2;
}				t_point;

typedef struct	s_incr
{
	int			xincr;
	int			yincr;
}				t_incr;

t_list			*reader(char *s);
int				stoi(t_list *begin_list, int ***tab);
int			draw_line(t_point *p, t_mlx *mlx);
void			draw_map(t_mlx *p, t_size size, int **tab);

#endif
