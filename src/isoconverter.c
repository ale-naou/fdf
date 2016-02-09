/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoconverter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:48:17 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/09 14:03:58 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_convertv(t_env *e)
{
	e->tmpx2 = (e->a[e->inc + e->p.lenx]->x * e->inf.scale) -
				e->a[e->inc + e->p.lenx]->z * e->inf.h;
	e->tmpy2 = e->a[e->inc + e->p.lenx]->y * e->inf.scale -
				e->a[e->inc + e->p.lenx]->z * e->inf.h;
	e->tmpx2 = e->tmpx2 - e->tmpy2;
	e->tmpy2 = (e->tmpx2 + e->tmpy2) / 2 +
				e->a[e->inc + e->p.lenx]->y * e->inf.scale;
}

void	iso_converth(t_env *e)
{
	e->tmpx2 = e->a[e->inc + 1]->x * e->inf.scale -
				e->a[e->inc + 1]->z * e->inf.h;
	e->tmpy2 = e->a[e->inc + 1]->y * e->inf.scale -
				e->a[e->inc + 1]->z * e->inf.h;
	e->tmpx2 = e->tmpx2 - e->tmpy2;
	e->tmpy2 = (e->tmpx2 + e->tmpy2) / 2 +
				e->a[e->inc + 1]->y *e->inf.scale;
}

void	iso_init(t_env *e)
{
	e->tmpx = e->a[e->inc]->x * e->inf.scale -
				e->a[e->inc]->z * e->inf.h;
	e->tmpy = e->a[e->inc]->y * e->inf.scale -
				e->a[e->inc]->z * e->inf.h;
	e->tmpx = e->tmpx - e->tmpy;
	e->tmpy = (e->tmpx + e->tmpy) / 2 +
				e->a[e->inc]->y * e->inf.scale;
}

void	backup(t_env *e)
{
	e->res.xres = e->tmpx;
	e->res.yres = e->tmpy;
	e->res.hres = e->inf.h;
	e->res.scaleres = e->inf.scale;

}
