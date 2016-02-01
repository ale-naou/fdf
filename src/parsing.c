/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:09:31 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/01 17:06:41 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*split(t_env *e, char *line)
{
	int		i;
	
	i = -1;
	while (line[e->il] == ' ')
		e->il++;
	while (line[e->il] != ' ' && line[e->il] != '\0')
		e->tmp[++i] = line[e->il++];
	e->tmp[i] = '\0';
	return (e->tmp);
}

static void	strsplitint(t_env *e, char *line)
{
	int		i;

	i = -1;
	e->il = 0;
	while (++i < e->p.lenx)
		e->p.tabz[e->is++] = ft_atoi(split(e, line));
}

static int	str_len(char *line)
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

static int	first_read(t_env *e, char *av)
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

void		parsing(t_env *e, char *av)
{
	e->fd = 0;
	e->ret = 0;
	e->i = 0;
	e->is = 0;
	e->p.lenmax = first_read(e, av);
	e->p.lenx = e->p.lenmax / e->p.leny;
	if ((e->fd = open(av, O_RDWR)) == -1)
		error(3);
	if (!(e->tmp = (char *)malloc(sizeof(char) * 8)))
		error(5);
	if (!(e->p.tabz = (int *)malloc(sizeof(int) * e->p.lenmax)))
		error(5);
	while ((e->ret = ft_get_next_line(e->fd, &e->line)) == 1)
		strsplitint(e, e->line);
}
