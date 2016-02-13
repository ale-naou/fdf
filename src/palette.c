/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:43:25 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/13 20:52:04 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	set_index(t_env *e)
{
	int		percent;
	int		index;

	percent = ((e->p.zmax - e->a[e->i]->z) * 100);
	index = (percent * e->pal.cn) / 100;
	index = e->pal.cn - index;
	return (index > 0 ? index - 1 : 0);
}

int		*color(t_env *e)
{
	int		pch;
	int		*color;

	if (!(color = (int *)malloc (sizeof(int) * 3)))
		error(3);
	pch = set_index(e);
	color[0] = (e->pal.c[e->pc][pch] % 256);
	color[1] = ((e->pal.c[e->pc][pch] >> 8) % 256);
	color[2] = ((e->pal.c[e->pc][pch] >> 16) % 256);
	return (color);
}

void	pal_init(t_env *e)
{
	int		i;
	int		j;
	int		fd;
	char 	*line;

	i = 0;
	fd = 0;
	line = NULL;
	if ((fd = open(e->arg.pal_name, O_RDONLY)) == -1)
		error(3);
	ft_get_next_line(fd, &line);
	ft_putendl(line);
	if ((e->pal.pn = ft_atoi(line)) == 0)
		error(3);
	ft_strdel(&line);
	ft_get_next_line(fd, &line);
	ft_putendl(line);
	if ((e->pal.cn = ft_atoi(line)) == 0)
		error(3);
	ft_strdel(&line);
	if (!(e->pal.c = (int **)malloc(sizeof(int) * e->pal.cn)))
		error(3);
	while (i < e->pal.pn)
	{
		if (!(e->pal.c[i] = (int *)malloc(sizeof(int) * 3)))
			error(3);
		j = 0;
		while (ft_get_next_line(fd, &line) == 1 && j < e->pal.cn)
			e->pal.c[i][j++] = ft_str_to_hex(line);
		i++;
	}
	if (close(fd) == -1)
		error(4);
	ft_strdel(&line);
}
