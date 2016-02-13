/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:24:51 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/13 15:23:30 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_env *e, int x, int y, int *color)
{
	int pos;

	if (e->a[e->i]->z != 0 || e->a[e->i + 1]->z != 0)
	{	
		pos = (x * e->img.opp) + (y * e->img.sl);	
		e->img.img[pos] = color[0];
		e->img.img[pos + 1] = color[1];
		e->img.img[pos + 2] = color[2];
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
