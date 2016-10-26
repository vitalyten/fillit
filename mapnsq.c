/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapnsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 22:03:12 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/25 16:12:34 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetclean(t_et *tet, char **map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[tet->body[i].y + tet->pos.y][tet->body[i].x + tet->pos.x] = '.';
		i++;
	}
}

int		getminsq(t_et *tet)
{
	float x;
	float n;
	float y;

	y = 1;
	n = 0;
	while (tet)
	{
		n++;
		tet = tet->next;
	}
	n *= 4;
	x = n;
	while (x - y > 0.000001)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return ((int)(x + 0.99));
}

char	**mapnew(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		showerr(1);
	map[size] = NULL;
	while (i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			showerr(1);
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

void	freemap(char **map)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

char	*ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (str);
}
