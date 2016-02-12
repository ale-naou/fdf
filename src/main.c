/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:12:43 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/12 18:51:31 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void init_env(t_env *e)
{
	e->fd = 0;
	e->ret = 0;
	e->i = 0;
	e->y = 0;
	e->inf.show = 0;
}

static void	read_args(t_env *e, int ac, char **av)
{
	int		i;
	
	i = -1;
	e->arg.winx = 0;
	e->arg.winy = 0;
	if ((e->arg.fd = open(av[1], O_RDWR)) == -1)
		error(3);
	e->arg.file = ft_strdup(av[1]);
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-ws") == 0 && i + 1 < ac)
		{
			e->arg.winx = ft_atoi(av[i + 1]);
			e->arg.winy = ft_atoi(av[i + 2]);
		}
	}
	e->arg.winx = (e->arg.winx < 420 || e->arg.winx > 2560 ? 600 : e->arg.winx);
	e->arg.winy = (e->arg.winy < 420 || e->arg.winy > 1440 ? 600 : e->arg.winy);
	e->win = mlx_new_window(e->mlx, e->arg.winx, e->arg.winy, e->arg.file);
}

static void	aff_help(void)
{
	ft_putchar('	');
	ft_putendl("Usage : ./fdf mapname.fdf [-ws window size]");
	ft_putchar('	');
	ft_putendl("[-ws] : [window width] [window height]");
	exit(0);
}

int			main(int ac, char **av)
{
	t_env	e;

	e.inf.h = 0.2;
	e.div = 2;
	if (ac == 2 || ac == 5)
	{
		if (ft_strcmp(av[1], "-help") == 0)
		{	
			ft_putendl("Debug main 2");
			aff_help();
		}
		e.mlx = mlx_init();
		init_env(&e);
		read_args(&e, ac, av);
		parsing(&e, av[1]);
		e.inf.scale = 2 ;
		e.orix = e.arg.winx / 2;
		e.oriy = e.arg.winy / 5;
		backup(&e);
		draw(&e);
		mlx_loop(e.mlx);
	}
	else
		aff_help();
	return (0);
}
