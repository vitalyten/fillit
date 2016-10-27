/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetsolve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:34:19 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/26 14:27:44 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tetsolve(t_et *tet)
{
	int		minsq;
	int		max;
	char	**map;

	max = maxln(tet);
	minsq = getminsq(tet);
	minsq = (max > minsq) ? max : minsq;
	map = mapnew(minsq);
	while (solvenext(tet, minsq, map) != 1)
	{
		minsq++;
		tet->next->pos.x = 0;
		tet->next->pos.y = 0;
		freemap(map);
		map = mapnew(minsq);
	}
	return (map);
}

int		solvenext(t_et *tet, int minsq, char **map)
{
	while (tet)
	{
		while (tetwrite(tet, map, minsq) != 1)
			if (tetmove(minsq, tet) == -1)
				return (-1);
		if (solvenext(tet->next, minsq, map) == 1)
			return (1);
		tetclean(tet, map);
		if (tetmove(minsq, tet) == -1)
			return (-1);
	}
	return (1);
}

int		tetwrite(t_et *t, char **m, int minsq)
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

int		tetmove(int minsq, t_et *tet)
{
	tet->pos.x++;
	if (tet->pos.x == minsq)
	{
		tet->pos.y++;
		tet->pos.x = 0;
	}
	if (tet->pos.y + maxy(tet) > minsq)
	{
		tet->pos.x = 0;
		tet->pos.y = 0;
		return (-1);
	}
	return (1);
}
