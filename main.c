/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:36:06 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/14 22:13:53 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // norm
#include "fillit.h"

int	main(int ac, char **av)
{
	t_et		*tet;
	int			fd;
	// char			*map;
	// int				min_sqr;
	printf("%s test\n", av[1]); // norm
	if (ac != 2)
		showerr(0);

	tet = NULL;
	tetalloc(tet);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	 	showerr(2);
	readfile(fd, tet);
	// tetalign(tet);
	// tettest(tet);


	// if (!(min_sqr = ft_resolve_it(t, &map, 0)))
	// {
	// 	write(1, "error\n", 6);
	// 	return (0);
	// }
	// 	ft_affichage_solution(map, min_sqr);
	// }
	return (0);
}

void	tetalloc(t_et *tet)
{
	if (!(tet = (t_et *)malloc(sizeof(t_et))))
		showerr(1);
	tet->next = NULL;
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

int	readfile(int fd, t_et *tet)
{
	char		*map;
	int			len;
	int			i;


	i = 0;
	map = ft_strnew(21);


	len = read(fd, map, 21);
	 	map[21] = '\0';
	settet(map, tet);

	// while ((len = read(fd, map, 21)) != 0)
	// {
	//  	map[len] = '\0';
	// 	if (i)
	// 	{
	// 		tetalloc(tet->next);
	// 		tet = tet->next;
	// 	}
	// 	settet(map, tet);
	// 	tet->c = 'A' + i;
	// 	i++;
	// }
	return (0);
}

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

void	*ft_memalloc(size_t size)
{
	void *mem;

	if ((mem = malloc(size)) && size)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)s++ = 0;
}
