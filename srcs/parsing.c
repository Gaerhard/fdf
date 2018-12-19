/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:22:56 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/15 20:49:28 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	clean_array(char ***array)
{
	int i;

	i = 0;
	while (array[0][i])
	{
		free(array[0][i]);
		i++;
	}
	free(*array);
}

static int	array_size(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static void	fill_matrix(t_m **tab, int i, int j, int z)
{
	tab[i][j].x = j;
	tab[i][j].y = i;
	tab[i][j].z = z;
}

int			stoi(t_list *begin_list, t_m **tab)
{
	t_list	*lst;
	char	**array;
	int		i;
	int		j;
	int		n_coords;

	lst = begin_list;
	i = -1;
	n_coords = -1;
	while (lst)
	{
		j = -1;
		array = ft_strsplit(lst->content, ' ');
		if (n_coords != -1 && n_coords != array_size(array))
			return (0);
		n_coords = array_size(array);
		if (!(tab[++i] = malloc(sizeof(t_m) * array_size(array))))
			return (0);
		while (array[++j])
			fill_matrix(tab, i, j, ft_atoi(array[j]));
		clean_array(&array);
		lst = lst->next;
	}
	ft_lstdel(&begin_list, ft_del);
	return (n_coords);
}

t_list		*reader(char *s)
{
	int		fd;
	char	*line;
	t_list	*begin_list;

	if ((fd = open(s, O_RDONLY)) < 0)
		return (NULL);
	begin_list = NULL;
	while (get_next_line(fd, &line))
	{
		ft_lstback(&begin_list, line, ft_strlen(line) + 1);
		ft_strdel(&line);
	}
	if (close(fd))
		return (NULL);
	return (begin_list);
}
