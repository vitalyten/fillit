/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:36:06 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/18 14:03:31 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // norm
#include "fillit.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_et		*tet;
	int			fd;
	// char			*map;
	// int				min_sqr;

	if (ac != 2)
		showerr(0);

	tet = tetalloc();
	if ((fd = open(av[1], O_RDONLY)) == -1)
	 	showerr(2);
	readfile(fd, tet);
	tetalign(tet);
	tettest(tet);


	// if (!(min_sqr = ft_resolve_it(t, &map, 0)))
	// {
	// 	write(1, "error\n", 6);
	// 	return (0);
	// }
	// 	ft_affichage_solution(map, min_sqr);
	// }
	return (0);
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

int	showerr(int code)
{
	if (code == 0)
		write(1, "usage: ./fillit filename\n", 25);
	if (code == 1)
		write(1, "memory error\n", 13);
	if (code == 2)
		write(1, "couldn't open file\n", 19);
	if (code == 3)
		write(1, "map error\n", 10);
	exit(-1);
}


