/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:09:04 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/01 15:26:19 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/include/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h> //

typedef struct		s_pars
{
	int				lenx;
	int				leny;
	int				lenmax;
	int				*tabz;
}					t_pars;

typedef struct		s_img
{
	void			*adr;
	char			*img;
	int				sl;
	int				bpp;
	int				opp;
	int				endian;	
}					t_img;

typedef struct		s_env
{
	int				i;
	int				imax;
	int				is;
	int				il;
	int				fd;
	int				ret;
	int				x;
	int				y;
	char			*line;
	char			*tmp;
	void			*mlx;
	void			*win;
	t_pars			p;
	t_img			i: 
}					t_env;


void		error(int c);
void		parsing(t_env *v, char *av);

#endif
