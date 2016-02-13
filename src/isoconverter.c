/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoconverter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:48:17 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/13 13:35:05 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_convertv(t_env *e)
{
	e->tmpx2 = (e->a[e->i + e->p.lenx]->x * e->inf.scale) -
				(e->a[e->i + e->p.lenx]->z * e->inf.scale) * e->inf.h;
	e->tmpy2 = e->a[e->i + e->p.lenx]->y * e->inf.scale -
				(e->a[e->i + e->p.lenx]->z * e->inf.scale) * e->inf.h;
	e->tmpx2 = e->tmpx2 - e->tmpy2;
	e->tmpy2 = (e->tmpx2 + e->tmpy2) / e->div +
				e->a[e->i + e->p.lenx]->y * e->inf.scale;
}

void	iso_converth(t_env *e)
{
	e->tmpx2 = e->a[e->i + 1]->x * e->inf.scale -
				(e->a[e->i + 1]->z * e->inf.scale) * e->inf.h;
	e->tmpy2 = e->a[e->i + 1]->y * e->inf.scale -
				(e->a[e->i + 1]->z * e->inf.scale) * e->inf.h;
	e->tmpx2 = e->tmpx2 - e->tmpy2;
	e->tmpy2 = (e->tmpx2 + e->tmpy2) / e->div +
				e->a[e->i + 1]->y *e->inf.scale;
}

void	iso_init(t_env *e)
{
	e->tmpx = e->a[e->i]->x * e->inf.scale -
				(e->a[e->i]->z * e->inf.scale) * e->inf.h;
	e->tmpy = e->a[e->i]->y * e->inf.scale -
				(e->a[e->i]->z * e->inf.scale) * e->inf.h;
	e->tmpx = e->tmpx - e->tmpy;
	e->tmpy = (e->tmpx + e->tmpy) / e->div +
				e->a[e->i]->y * e->inf.scale;
}

void	backup(t_env *e)
{
	e->res.x = e->orix;
	e->res.y = e->oriy;
	e->res.h = e->inf.h;
	e->res.scale = e->inf.scale;
	e->res.div = e->div;
}
