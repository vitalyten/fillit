/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:36:06 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/25 17:41:27 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_et	*tet;
	int		fd;
	char	**map;

	if (ac != 2)
		showerr(0);
	tet = tetalloc();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		showerr(2);
	readfile(fd, tet);
	tetalign(tet);
	tettest(tet);
	map = tetsolve(tet);
	printmap(map);
	return (0);
}

void	printmap(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			write(1, &map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

t_et	*tetalloc(void)
{
	t_et *tet;

	if (!(tet = (t_et *)malloc(sizeof(t_et))))
		showerr(1);
	tet->pos.x = 0;
	tet->pos.y = 0;
	tet->next = NULL;
	return (tet);
}

int		showerr(int code)
{
	if (code == 0)
		write(1, "usage: ./fillit \"filename\"\n", 27);
	else
		write(1, "error\n", 6);
	exit(-1);
}
