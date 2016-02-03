/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:17:13 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/03 22:02:20 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		img_pixel_put(e, e->orix + e->tmpx + (c * dh) / m, 
						e->oriy + e->tmpy + (c * dl) / m, 0xFF0000);
}

void		draw(t_env *e)
{
	e->inc = 0;
	img_init(e);
	while (e->inc + 1 < e->p.lenmax)
	{
		iso_init(e);
		if (e->a[e->inc]->y == e->a[e->inc + 1]->y)
		{
			iso_converth(e);
			draw_line(e); 
		}
		if (e->inc + e->p.lenx + 1 <= e->p.lenmax)
		{
			iso_convertv(e);
			draw_line(e);
		}
		e->inc++;
	}
	mlx_hook(e->win, 2, 1, keyfnc, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	mlx_loop(e->mlx);
}
