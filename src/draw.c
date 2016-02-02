/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:17:13 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/02 14:55:37 by ale-naou         ###   ########.fr       */
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
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->winx, e->winy, "fdf");
	while (e->inc + 1 < e->p.lenmax)
	{
		e->tmpx = e->a[e->inc]->x * 20;
		e->tmpy = e->a[e->inc]->y * 20;
//		ft_putstr("e->a[i]->x :");
//		ft_putnbr(e->a[i]->x);
//		ft_putstr(",	");
//		ft_putstr("e->a[i]->y :");
//		ft_putnbr(e->a[i]->y);
//		ft_putstr("\n");
		if (e->a[e->inc]->y == e->a[e->inc + 1]->y)
		{
			e->tmpx2 = e->a[e->inc + 1]->x * 20;
			e->tmpy2 = e->a[e->inc + 1]->y * 20;
			draw_line(e); 
		}
		e->inc++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	mlx_loop(e->mlx);
}
