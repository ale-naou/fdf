/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:24:51 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/15 15:15:53 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_env *e, int x, int y)
{
	int pos;

	if (x >= 0 && y >= 0 && x < e->arg.winx && y < e->arg.winy)
	{
		if (e->pal_num == 0 || e->pal_num == 1)
			palette_mono(e, x, y);
		else if (e->pal_num == 2 || e->pal_num == 3)
			palette_bicolor(e, x, y);
		else if (e->a[e->i]->z == 0)
		{
			pos = (x * e->img.opp) + (y * e->img.sl);	
			e->img.img[pos] = 100;
			e->img.img[pos + 1] = 100;
			e->img.img[pos + 2] = 100;
		}
		else if (e->a[e->i]->z > 0)
		{	
			pos = (x * e->img.opp) + (y * e->img.sl);	
			e->img.img[pos] = 0;
			e->img.img[pos + 1] = 255;
			e->img.img[pos + 2] = 0;
		}
		else
		{
			pos = (x * e->img.opp) + (y * e->img.sl);	
			e->img.img[pos] = 255;
			e->img.img[pos + 1] = 255;
			e->img.img[pos + 2] = 255;
		}
	}
}

void	img_init(t_env *e)
{
	if (!(e->img.adr = mlx_new_image(e->mlx, e->arg.winx, e->arg.winy)))
		error(6);
	if (!(e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp, &e->img.sl,
			&e->img.endian)))
		error(7);
	e->img.opp = e->img.bpp / 8;
}
