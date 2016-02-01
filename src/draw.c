/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:17:13 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/01 21:06:35 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_env *e)
{
	int		dh;
	int		dl;
	int		c;
	int		m;

	dh = (e->x + 1) - e->x;
	dl = (e->y + 1) - e->y;
	c = -1;
	m = abs(dh) > abs(dl) ? abs(dh) : abs (dl);
	while (++c < m)
		img_pixel_put(e, e->orix + e->x * 10 + (c * dh) / m, 
						e->oriy + e->y * 10 + (c * dl) / m, 0xFF0000);
}

void		draw(t_env *e)
{
	int i;

	i = 0;
	e->y = 0;
	e->inc = 0;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->winx, e->winy, "fdf");
	while (i + 1 < e->p.lenmax)
	{
		e->x = 0;
		while (e->x < e->p.lenx)
		{
			draw_line(e);
			e->x = e->x + 1;
			i++;
		}
		e->y = e->y + 1;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	mlx_loop(e->mlx);
}
