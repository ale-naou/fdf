/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:12:43 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/09 18:10:26 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;
	e.winx = 2560;
	e.winy = 1440;
	e.orix = 250;
	e.oriy = 50;
	e.inf.scale = 25;
	e.inf.h = 10;
	e.div = 2;
	if (ac != 2)
	{
		ac == 1 ? error(1) : error(2);
	}
	parsing(&e, av[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.winx, e.winy, "fdf");
	backup(&e);
	draw(&e);
	return (0);
}
