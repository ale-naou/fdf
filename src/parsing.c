/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:09:31 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/15 15:15:54 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_parser(t_env *e)
{
	e->p.lenx = 0;
	e->p.leny = 0;
	e->p.lenmax = 0;
	e->p.zmin = 2147483647;
	e->p.zmax = -2147483648;
}

static t_axis	*new_point(t_env *e, char *tab)
{
	t_axis *new;
	
	if (!(new = (t_axis *)malloc(sizeof(t_axis))))
		return (NULL);
	new->x = e->x;
	new->y = e->y;
	new->z = ft_atoi(tab);
	e->p.zmin = (new->z < e->p.zmin ? new->z : e->p.zmin);		
	e->p.zmax = (new->z > e->p.zmax ? new->z : e->p.zmax);
	ft_strdel(&tab);
	return (new);
}

static int		str_len(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9' &&
			(line[i + 1] == ' ' || line[i + 1] == '\0'))
			len++;
		else if ((line[i] < '0' || line[i] > '9') &&
				line[i] != '-' && line[i] != ' ')
			error(3);
		i++;
	}
	return (len);
}

static int		first_read(t_env *e)
{
	int		i;
	int		imax;

	i = 0;
	imax = 0;
	while (ft_get_next_line(e->arg.fd, &e->line) == 1)
	{
		i = str_len(e->line);
		if (i > imax)
			imax = i;
		e->p.leny++;
	}
	if (close(e->arg.fd) == -1)
		error(4);
	return (imax * e->p.leny);
}

void			parsing(t_env *e, char *av)
{
	int		i;

	i = 0;
	init_parser(e);
	e->p.lenmax = first_read(e);
	e->p.lenx = e->p.lenmax / e->p.leny;
	if (!(e->a = (t_axis **)malloc(sizeof(t_axis *) * e->p.lenmax)))
		error(5);
	if ((e->arg.fd = open (av, O_RDWR)) == -1)
		error(3);
	while (ft_get_next_line(e->arg.fd, &e->line) == 1)
	{
		e->tab = ft_strsplit(e->line, ' ');
		e->x = -1;
		while (++e->x < e->p.lenx)
			e->a[i++] = new_point(e, e->tab[e->x]);
		e->y++;
		free(e->tab);
		e->tab = NULL;
	}
	e->p.zlenmax = abs(e->p.zmax) + abs(e->p.zmin);
	e->p.zstep = e->p.zlenmax / 2;
	if (close(e->arg.fd) == -1)
		error(4);
}
