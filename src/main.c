/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:12:43 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/11 14:29:35 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;

	e.winx = 2560;
	e.winy = 1440;
//	e.winx = 500;
//	e.winy = 500;
	e.inf.h = 0.2;
	e.div = 2;
	e.inf.show = 0;
	if (ac != 2)
	{
		ac == 1 ? error(1) : error(2);
	}
	parsing(&e, av[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.winx, e.winy, "fdf");
	e.inf.scale = 2 ;
	e.orix = e.winx / 2;
	e.oriy = e.winy / 5;
	backup(&e);
	draw(&e);
	return (0);
}
