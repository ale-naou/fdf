/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:24:51 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/01 21:06:34 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_env *e, int x, int y, int color)
{
	int pos;

	if (x < e->winx && y < e->winy && x >= 0 && y >= 0)
	{
		if (e->p.tabz[e->inc] != 0)
		{
			pos = (x * e->img.opp) + (y * e->img.sl);	
			e->img.img[pos] = 255;
			e->img.img[pos + 1] = 255;
			e->img.img[pos + 2] = 255;
		}
		else
		{
			pos = (x * e->img.opp) + (y * e->img.sl);	
			e->img.img[pos] = color % 256;
			e->img.img[pos + 1] = (color / 256) % 256;
			e->img.img[pos + 2] = ((color / 256) / 256) % 256;		
		}
		e->inc++;
	}
}

void	img_init(t_env *e)
{
	if (!(e->img.adr = mlx_new_image(e->mlx, 1000, 1000)))
		error(6);
	if (!(e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp, &e->img.sl,
			&e->img.endian)))
		error(7);
	e->img.opp = e->img.bpp / 8;
}