/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:37:42 by ale-naou          #+#    #+#             */
/*   Updated: 2016/01/31 21:06:42 by ale-naou         ###   ########.fr       */
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
	exit(1);
}
