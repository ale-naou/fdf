/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:12:43 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/03 17:18:42 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;
	e.winx = 1000;
	e.winy = 600;
	e.orix = 250;
	e.oriy = 50;
	e.inf.scale = 25;
	if (ac != 2)
	{
		ac == 1 ? error(1) : error(2);
	}
	parsing(&e, av[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.winx, e.winy, "fdf");
	ft_putendl("Prout");
	img_init(&e);
	printf("%s%d%s", "lenx	= ", e.p.lenx, ";\n");
	printf("%s%d%s", "leny	= ", e.p.leny, ";\n");
	printf("%s%d%s", "lmax	= ", e.p.lenmax, ";\n");
	printf("%s%d%s", "sl	= ", e.img.sl, ";\n");
	printf("%s%d%s", "bpp	= ", e.img.bpp, ";\n");
	printf("%s%d%s", "opp	= ", e.img.opp, ";\n");
	draw(&e);
	return (0);
}
