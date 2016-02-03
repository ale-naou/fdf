/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfnc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:09:45 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/03 20:32:44 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyfnc(int key, t_env *e)
{
	if (key == 53)
		exit (0);
	e->orix = key == 123 ? e->orix - 10 : e->orix + 0;
	e->orix = key == 124 ? e->orix + 10 : e->orix + 0;
	e->oriy = key == 126 ? e->oriy - 10 : e->oriy + 0;
	e->oriy = key == 125 ? e->oriy + 10 : e->oriy + 0;
	mlx_destroy_image(e->mlx, e->img.adr);
	draw(e);
	return (0);
}
