/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:37:42 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/01 20:16:32 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int c)
{
	if (c == 1)
		ft_putendl("Give me Something ...");
	if (c == 2)
		ft_putendl("I cant handle this much !");
	if (c == 3)
		ft_putendl("openfd() failed");
	if (c == 4)
		ft_putendl("closefd() failed");
	if (c == 5)
		ft_putendl("Alloc failed");
	if (c == 6)
		ft_putendl("e->img.adr not created");
	if (c == 7)
		ft_putendl("e->img.img not created");
	exit(1);
}
