/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:50:30 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/18 20:25:38 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_dot
{
	int				x;
	int				y;
}					t_dot;

typedef struct		s_et
{
	t_dot			body[4];
	t_dot			pos;
	struct s_et		*next;
	char			c;
}					t_et;

static const t_dot		g_alltet[19][4] = {
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 3, .y = 0}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 0, .y = 2}, {.x = 0, .y = 3}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 0, .y = 2}, {.x = 1, .y = 2}},
	{{.x = 1, .y = 0}, {.x = 1, .y = 1}, {.x = 0, .y = 2}, {.x = 1, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 0, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 1, .y = 1}, {.x = 1, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
	{{.x = 2, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 0, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 2, .y = 1}},
	{{.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 1, .y = 2}},
	{{.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 0, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 1, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 1, .y = 2}},
	{{.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}},
	{{.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 0, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}}
};

int		showerr(int code);
t_et	*tetalloc(void);
int		readfile(int fd, t_et *tet);
void	settet(char *map, t_et *tet);
void	setpos(t_et *tet, int i, int x, int y);
void	tetalign(t_et *tet);
void	tettest(t_et *tet);
int		tetcmp(t_et *tet);
int		getminsqr(t_et *tet);
char	**tetsolve(t_et *tet);
void    printmap(char **map);
char	**tetsolve(t_et *tet);
int	solvenext(t_et *tet, int minsq, char **map);
int	tetwrite(t_et *t, char **m, int minsq);
int tetmove(int minsq, t_et *tet);
int	maxy(t_et *tet);
int	maxx(t_et *tet);
int	getminsq(t_et *tet);
char **mapnew(int size);
void    freemap(char **map);
char	*ft_strnew(size_t size);

#endif
