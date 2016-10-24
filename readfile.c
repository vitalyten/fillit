/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:00:45 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/18 14:31:50 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		readfile(int fd, t_et *tet)
{
	char		*map;
	int			len;
	int			i;

	i = 0;
	map = ft_strnew(21);
	while ((len = read(fd, map, 21)) != 0)
	{
		map[len] = '\0';
		if (i)
		{
			tet->next = tetalloc();
			tet = tet->next;
		}
		settet(map, tet);
		tet->c = 'A' + i;
		i++;
	}
	return (0);
}

void	settet(char *map, t_et *tet)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (*map)
	{
		if (*map == '#' && x < 4 && y < 4 && i < 4)
			setpos(tet, i++, x++, y);
		else if (*map == '.' && x < 4 && y < 4)
			x++;
		else if (*map == '\n' && x == 4 && y < 4)
		{
			y++;
			x = 0;
		}
		else if (*map == '\n' && x == 0 && y == 4)
			y++;
		else
			showerr(3);
		map++;
	}
}

void	setpos(t_et *tet, int i, int x, int y)
{
	tet->body[i].x = x;
	tet->body[i].y = y;
}
