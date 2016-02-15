/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:43:25 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/15 15:15:57 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	p_bicolor2(t_env *e, int x, int y)
{
	int pos;

	if (x >= 0 && y >= 0 && x < e->arg.winx && y < e->arg.winy)
	{
		if (e->a[e->i]->z <= e->p.zstep)
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

void	palette_bicolor(t_env *e, int x, int y)
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
			p_bicolor2(e, x, y);
	}
}

void	palette_mono(t_env *e, int x, int y)
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
