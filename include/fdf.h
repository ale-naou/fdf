/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:09:04 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/09 18:24:05 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/include/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h> //

typedef struct		s_axis
{
	int				x;
	int				y;
	int				z;
}					t_axis;

typedef struct		s_pars
{
	int				lenx;
	int				leny;
	int				lenmax;
}					t_pars;

typedef struct		s_infos
{
	int				scale;
	int				h;
}					t_infos;

typedef struct		s_img
{
	void			*adr;
	char			*img;
	int				sl;
	int				bpp;
	int				opp;
	int				endian;
}					t_img;

typedef struct		s_reset
{
	int				xres;
	int				yres;
	int				hres;
	int				scaleres;
	int				divres;

}					t_reset;

typedef struct		s_env
{
	int				i;
	int				imax;
	int				inc; //
	int				fd;
	int				ret;
	int				x;
	int				y;
	int				winx;
	int				winy;
	int				orix;
	int				oriy;
	int				tmpx;
	int				tmpy;
	int				tmpx2;
	int				tmpy2;
	int				div;
	char			*line;
	char			**tab;
	char			*tmp;
	void			*mlx;
	void			*win;
	t_axis			**a;
	t_pars			p;
	t_img			img;
	t_infos			inf;
	t_reset			res;
}					t_env;


void		error(int c);
void		parsing(t_env *v, char *av);
void		draw(t_env *e);
void		img_init(t_env *e);
void		img_pixel_put(t_env *e, int x, int y, int color);
void		iso_init(t_env *e);
void		iso_converth(t_env *e);
void		iso_convertv(t_env *e);
void		backup(t_env *e);
int			keyfnc(int key, t_env *e);

#endif
