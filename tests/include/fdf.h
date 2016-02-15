/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:09:04 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/15 17:31:20 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/include/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_axis
{
	float			x;
	float			y;
	float			z;
}					t_axis;

typedef struct		s_pars
{
	int				lenx;
	int				leny;
	int				lenmax;
	int				zmin;
	int				zmax;
	int				zlenmax;
	int				zstep;
}					t_pars;

typedef struct		s_infos
{
	float			scale;
	float			h;
	int				show;
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
	float			h;
	float			scale;
	int				x;
	int				y;
	int				div;

}					t_reset;

typedef struct		s_args
{	
	int				fd;
	int				winx;
	int				winy;
	char			*file;
	char			*pal_name;
}					t_args;

typedef struct		s_env
{
	float			orix;
	float			oriy;
	float			div;
	int				i;
	int				fd;
	int				ret;
	int				x;
	int				y;
	int				pal_num;
	int				tmpx;
	int				tmpy;
	int				tmpx2;
	int				tmpy2;
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
	t_args			arg;
}					t_env;


void		error(int c);
void		parsing(t_env *e, char *av);
void		draw(t_env *e);
void		img_init(t_env *e);
void		img_pixel_put(t_env *e, int x, int y);
void		palette_mono(t_env *e, int x, int y);
void		palette_bicolor(t_env *e, int x, int y, int z);
void		iso_init(t_env *e);
void		iso_converth(t_env *e);
void		iso_convertv(t_env *e);
void		backup(t_env *e);
void		optionsdisplay(t_env *e);
int			keyfnc(int key, t_env *e);

#endif
