/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:12:43 by ale-naou          #+#    #+#             */
/*   Updated: 2016/01/31 21:06:44 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;
	int i;
	int	n;

	i = 0;
	n = 0;
	if (ac != 2)
	{
		ac == 1 ? error(1) : error(2);
	}
	parsing(&e, av[1]);
	printf("%s%d%s", "lenx	= ", e.p.lenx, ";\n");
	printf("%s%d%s", "leny	= ", e.p.leny, ";\n");
	printf("%s%d%s", "lmax	= ", e.p.lenmax, ";\n");
	while (i < e.p.lenmax)
	{
		ft_putnbr(e.p.tabz[i]);
		ft_putchar(' ');
		if (n == 19)
		{
			ft_putchar('\n');
			n = 0;
		}
		i++;
		n++;
	}
	return (0);
}
