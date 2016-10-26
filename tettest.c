/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tettest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:25:41 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/18 14:32:21 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetalign(t_et *tet)
{
	int minx;
	int miny;
	int i;

	while (tet)
	{
		minx = tet->body[0].x;
		miny = tet->body[0].y;
		i = 1;
		while (i < 4)
		{
			minx = (tet->body[i].x < minx) ? tet->body[i].x : minx;
			miny = (tet->body[i].y < miny) ? tet->body[i].y : miny;
			i++;
		}
		i = 0;
		while (i < 4)
		{
			tet->body[i].x -= minx;
			tet->body[i].y -= miny;
			i++;
		}
		tet = tet->next;
	}
}

int		tetcmp(t_et *tet)
{
	int i;

	i = 0;
	while (i < 19)
	{
		if (tet->body[0].x == g_alltet[i][0].x &&
			tet->body[1].x == g_alltet[i][1].x &&
			tet->body[2].x == g_alltet[i][2].x &&
			tet->body[3].x == g_alltet[i][3].x &&
			tet->body[0].y == g_alltet[i][0].y &&
			tet->body[1].y == g_alltet[i][1].y &&
			tet->body[2].y == g_alltet[i][2].y &&
			tet->body[3].y == g_alltet[i][3].y)
			return (0);
		i++;
	}
	return (-1);
}

void	tettest(t_et *tet)
{
	while (tet)
	{
		if (tetcmp(tet) == -1)
			showerr(3);
		tet = tet->next;
	}
}
