/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetsolve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:34:19 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/20 20:54:27 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tetsolve(t_et *tet)
{
	int		minsq;
	char	**map;

	minsq = getminsq(tet);
	map = mapnew(minsq);
	while (solvenext(tet, minsq, map) != 1)
	{
		minsq++;
		freemap(map);
		map = mapnew(minsq);
	}
    return (map);
}

int	solvenext(t_et *tet, int minsq, char **map)
{
	tet->pos.x = 0;
    tet->pos.y = 0;
    while (tetwrite(tet, map, minsq) != 1)
        if (tetmove(minsq, tet) == -1)
            return (-1);
	printmap(map);
    if (tet->next)
        return (solvenext(tet->next, minsq, map));
	return (1);
}

int	tetwrite(t_et *t, char **m, int minsq)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (t->body[i].x + t->pos.x >= minsq)
			break ;
		if (t->body[i].y + t->pos.y >= minsq)
			break ;
		if (m[t->body[i].y + t->pos.y][t->body[i].x + t->pos.x] != '.')
			break ;
		i++;
	}
	if (i == 4)
	{
		i = 0;
		while (i < 4)
		{
			m[t->body[i].y + t->pos.y][t->body[i].x + t->pos.x] = t->c;
			i++;
		}
		return (1);
	}
	return (0);
}

int tetmove(int minsq, t_et *tet)
{
	tet->pos.x++;
	if (tet->pos.y + maxy(tet) > minsq &&
		tet->pos.x + maxx(tet) > minsq)
		return (-1);
	if (tet->pos.x == minsq)
	{
		tet->pos.y++;
		tet->pos.x = 0;
	}
	return (1);
}

int	maxy(t_et *tet)
{
	int i;
	int max;

	i = 1;
    max = tet->body[0].y;
	while (i < 4)
	{
		if (tet->body[i].y > max)
			max = tet->body[i].y;
        i++;
	}
	return (max);
}

int	maxx(t_et *tet)
{
	int i;
	int max;

	i = 1;
    max = tet->body[0].x;
	while (i < 4)
	{
		if (tet->body[i].x > max)
			max = tet->body[i].x;
        i++;
	}
	return (max);
}
