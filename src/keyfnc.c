/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfnc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:09:45 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/11 16:34:21 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void scale(int key, t_env *e)
{
	if (e->inf.scale > 1)
		e->inf.scale = key == 78 ? e->inf.scale - 1 : e->inf.scale;
	e->inf.scale = key == 69 ? e->inf.scale + 1 : e->inf.scale;
	e->inf.h = key == 121 ? e->inf.h - 0.2 : e->inf.h;
	e->inf.h = key == 116 ? e->inf.h + 0.2 : e->inf.h;
}

static void	move(int key, t_env *e)
{
	e->orix = key == 123 ? e->orix - 10 : e->orix;
	e->orix = key == 124 ? e->orix + 10 : e->orix;
	e->oriy = key == 126 ? e->oriy - 10 : e->oriy;
	e->oriy = key == 125 ? e->oriy + 10 : e->oriy;
	e->div = key == 86 ? e->div + 1 : e->div;
	if (e->div > 1) 
		e->div = key == 88 ? e->div - 1 : e->div;
}

static void	reset(t_env *e)
{
	e->orix = e->res.xres;
	e->oriy = e->res.yres;
	e->inf.h = e->res.hres;
	e->inf.scale = e->res.scaleres;
	e->div = e->res.divres;
}

int		keyfnc(int key, t_env *e)
{
//	printf("%d", key);
	if (key == 31)
		e->inf.show++;
	if (key == 53)
		exit (0);
	if ((key >= 123 && key <= 126) || key == 86 || key == 88)
		move(key, e);
	if (key == 69 || key == 78 || key == 121 || key == 116)
		scale(key, e);
	if (key == 115)
		reset(e);
	mlx_destroy_image(e->mlx, e->img.adr);
	draw(e);
	return (0);
}
