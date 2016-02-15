/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:17:13 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/15 14:16:12 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	valuesdisplay(t_env *e)
{
	int x;
	int y;

	x = e->arg.winx - 150;
	y = e->arg.winy - 100;
	mlx_string_put(e->mlx, e->win, x, y, 0xFFFFFF, "orix = ");
	mlx_string_put(e->mlx, e->win, x + 75, y, 0xFFFFFF, ft_itoa(e->orix));
	mlx_string_put(e->mlx, e->win, x, y + 20, 0xFFFFFF, "oriy = ");
	mlx_string_put(e->mlx, e->win, x + 75, y += 20, 0xFFFFFF, ft_itoa(e->oriy));
}

void	optionsdisplay(t_env *e)
{
	int		x;
	int		y;

	x = e->arg.winx / 50;
	y = e->arg.winy / 50;
	if ((e->inf.show % 2) == 0)
		mlx_string_put(e->mlx, e->win, x, y, 0xFFFFFF, 
					"Use [o] to show options");
	else
	{
		mlx_string_put(e->mlx, e->win, x, y, 0xFFFFFF, 
				"Use [arrows]       to move map");
		mlx_string_put(e->mlx, e->win, x, y += 20, 0xFFFFFF, 
				"Use [+] [-]        to zoom in / zoom out");
		mlx_string_put(e->mlx, e->win, x, y += 20, 0xFFFFFF, 
				"Use [pgup] [pgdwn] to increase / decrease altitude");
		mlx_string_put(e->mlx, e->win, x, y += 20, 0xFFFFFF, 
				"Use [4] [6]        to change inclination");
		valuesdisplay(e);
	}
}

static void	draw_line(t_env *e)
{
	int		dh;
	int		dl;
	int		c;
	int		m;

	dh = e->tmpx2 - e->tmpx;
	dl = e->tmpy2 - e->tmpy;
	c = -1;
	m = abs(dh) > abs(dl) ? abs(dh) : abs (dl);
	while (++c < m)
	{
		if (((e->tmpx + e->orix) > e->arg.winx && 
			(e->tmpx2 + e->orix) >= e->arg.winx) ||
			((e->tmpy + e->oriy) > e->arg.winy && 
			(e->tmpy2 + e->oriy) >= e->arg.winy) ||
			(((e->tmpx + e->orix) < 0 && (e->tmpx2 + e->orix) < 0) || 
			((e->tmpy + e->oriy) < 0 && (e->tmpy2 + e->oriy) < 0)))
			break;
		img_pixel_put(e, e->orix + e->tmpx + (c * dh) / m, 
					e->oriy + e->tmpy + (c * dl) / m);
	}
}

void		draw(t_env *e)
{
	e->i = 0;
	img_init(e);
	while (e->i + 1 < e->p.lenmax)
	{
		iso_init(e);
		if (e->a[e->i]->y == e->a[e->i + 1]->y)
		{
			iso_converth(e);
			draw_line(e); 
		}
		if (e->i + e->p.lenx < e->p.lenmax)
		{
			iso_convertv(e);
			draw_line(e);
		}
		e->i++;
	}
	mlx_hook(e->win, 2, 1, keyfnc, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	optionsdisplay(e);
	mlx_loop(e->mlx);
}
