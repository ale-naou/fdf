/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfnc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:09:45 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/09 14:04:50 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyfnc(int key, t_env *e)
{
	if (key == 53)
		exit (0);
	e->orix = key == 123 ? e->orix - 10 : e->orix;
	e->orix = key == 124 ? e->orix + 10 : e->orix;
	e->oriy = key == 126 ? e->oriy - 10 : e->oriy;
	e->oriy = key == 125 ? e->oriy + 10 : e->oriy;
	printf("%d", key);
	if (e->inf.scale > 1)
		e->inf.scale = key == 78 ? e->inf.scale - 1 : e->inf.scale;
	if (key == 115)

	e->inf.scale = key == 69 ? e->inf.scale + 1 : e->inf.scale;
	e->inf.h = key == 121 ? e->inf.scale + 1 : e->inf.scale;
	e->inf.h = key == 116 ? e->inf.scale - 1 : e->inf.scale;
	mlx_destroy_image(e->mlx, e->img.adr);
	draw(e);
	return (0);
}
