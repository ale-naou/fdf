/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:12:43 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/02 14:28:06 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;
	int i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	e.winx = 1000;
	e.winy = 1000;
	e.orix = 100;
	e.oriy = 100;
	if (ac != 2)
	{
		ac == 1 ? error(1) : error(2);
	}
	parsing(&e, av[1]);
	ft_putnbr(e.a[189]->h);
	ft_putchar('\n');
	printf("%s%d%s", "lenx	= ", e.p.lenx, ";\n");
	printf("%s%d%s", "leny	= ", e.p.leny, ";\n");
	printf("%s%d%s", "lmax	= ", e.p.lenmax, ";\n");
	img_init(&e);
	printf("%s%d%s", "sl	= ", e.img.sl, ";\n");
	printf("%s%d%s", "bpp	= ", e.img.bpp, ";\n");
	printf("%s%d%s", "opp	= ", e.img.opp, ";\n");
	draw(&e);
	return (0);
}
