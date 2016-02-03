/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:09:31 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/03 15:48:07 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_axis	*new_point(t_env *e, char *tab)
{
	t_axis *new;
	
	if (!(new = (t_axis *)malloc(sizeof(t_axis))))
		return (NULL);
	new->x = e->x;
	new->y = e->y;
	new->h = ft_atoi(tab);
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
		i++;
	}
	return (len);
}

static int		first_read(t_env *e, char *av)
{
	e->fd = 0;
	e->ret = 0;
	e->i = 0;
	e->imax = 0;
	e->p.leny = 0;
	if ((e->fd = open(av, O_RDWR)) == -1)
		error(3);
	while ((e->ret = ft_get_next_line(e->fd, &e->line)) == 1)
	{
		e->i = str_len(e->line);
		if (e->i > e->imax)
			e->imax = e->i;
		e->p.leny++;
	}
	if (close(e->fd) == -1)
		error(4);
	return (e->imax * e->p.leny);
}

void			parsing(t_env *e, char *av)
{
	e->fd = 0;
	e->ret = 0;
	e->p.lenmax = first_read(e, av);
	e->p.lenx = e->p.lenmax / e->p.leny;
	if ((e->fd = open(av, O_RDWR)) == -1)
		error(3);
	if (!(e->a = (t_axis **)malloc(sizeof(t_axis *) * e->p.lenmax)))
		error(5);
	e->y = 0;
	e->i = 0;
	while ((e->ret = ft_get_next_line(e->fd, &e->line)) == 1)
	{
		e->tab = ft_strsplit(e->line, ' ');
		e->x = -1;
		while (e->tab[++e->x] != NULL)
			e->a[e->i++] = new_point(e, e->tab[e->x]);
		e->y++;
		free(e->tab);
		e->tab = NULL;
	}
	if (close(e->fd) == -1)
		error(4);	
}
