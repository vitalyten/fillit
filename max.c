/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:57:46 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/25 17:37:21 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		maxy(t_et *tet)
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

int		maxx(t_et *tet)
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

int		maxln(t_et *tet)
{
	int max;
	int i;

	max = 0;
	while (tet)
	{
		i = 0;
		while (i < 4)
		{
			max = (tet->body[i].x > max) ? tet->body[i].x : max;
			max = (tet->body[i].y > max) ? tet->body[i].y : max;
			i++;
		}
		tet = tet->next;
	}
	return (max + 1);
}
