/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:43:25 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/15 22:34:50 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	p_bicolor2(t_env *e, int x, int y, int z)
{
	int pos;

	(void)z;
	if (x >= 0 && y >= 0 && x < e->arg.winx && y < e->arg.winy)
	{
		if (e->a[e->i]->z >= e->p.zstep ||
			(e->i + e->p.lenx < e->p.lenmax &&			 
			e->a[e->i + e->p.lenx]->z >= e->p.zstep &&
			e->a[e->i]->z < e->p.zstep) ||
			(e->i + 1 < e->p.lenmax && 
			 e->a[e->i]->z < e->p.zstep &&
			 e->a[e->i + 1]->z >= e->p.zstep))
		{
			pos = (x * e->img.opp) + (y * e->img.sl);
			e->img.img[pos] = 255;
			e->img.img[pos + 1] = 255;
			e->img.img[pos + 2] = 0;
		}
		else
		{
			pos = (x * e->img.opp) + (y * e->img.sl);
			e->img.img[pos] = 0;
			e->img.img[pos + 1] = 255;
			e->img.img[pos + 2] = 255;
		}
	}
}

void		palette_bicolor(t_env *e, int x, int y, int z)
{
	int pos;

	if (x >= 0 && y >= 0 && x < e->arg.winx && y < e->arg.winy)
	{
		if (e->pal_num == 2)
		{
			if (e->a[e->i]->z <= e->p.zstep)
			{
				pos = (x * e->img.opp) + (y * e->img.sl);
				e->img.img[pos] = 255;
				e->img.img[pos + 1] = 255;
				e->img.img[pos + 2] = 255;
			}
			else
			{
				pos = (x * e->img.opp) + (y * e->img.sl);
				e->img.img[pos] = 255;
				e->img.img[pos + 1] = 0;
				e->img.img[pos + 2] = 255;
			}
		}
		else
			p_bicolor2(e, x, y, z);
	}
}

void		palette_mono(t_env *e, int x, int y)
{
	int pos;

	if (x >= 0 && y >= 0 && x < e->arg.winx && y < e->arg.winy)
	{
		if (e->pal_num == 0)
		{
			pos = (x * e->img.opp) + (y * e->img.sl);
			e->img.img[pos] = 255;
			e->img.img[pos + 1] = 255;
			e->img.img[pos + 2] = 255;
		}
		else if (e->pal_num == 1)
		{
			pos = (x * e->img.opp) + (y * e->img.sl);
			e->img.img[pos] = 0;
			e->img.img[pos + 1] = 255;
			e->img.img[pos + 2] = 0;
		}
	}
}
