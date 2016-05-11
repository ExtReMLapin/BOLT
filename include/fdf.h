/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:20:45 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/14 13:20:47 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_julia
{
	double 		nR; 
	double		nI; 
	double		oR;
	double		oI;
	int			color;
	int			h;
	int			w;
	int			x;
	int			y;
	int			i;
}					t_julia;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
	void			*img;
	unsigned int	rendermode;
	int				c;
	int				bpp;
	char			*data;
	int				size_line;
	int				endian;
	int				maxIterations;
	double			cRe;
	double			cIm;
	double			oy;
	double			ox;;
	double			zm;
	t_julia*		ja;

}					t_env;

typedef struct		s_box
{
	int				x;
	int				y;
	int				w;
	int				h;
	int				c;
}					t_box;

typedef struct	s_hsv
{
	double	i;
	double	f;
	double	l;
	double	m;
	double	n;
}				t_hsv;

void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				error(char const *s);
void				errornohalt(char const *s);
unsigned long		creatergb(int r, int g, int b);
int					fastmlx_pixel_put(t_env *env, int x, int y, int color);
int					draw(t_env *env);
void				goodsize(t_env *env);
void				drawmap2d(t_env *env);
int					hookkey(int keycode, t_env *env);
int 				mousekey( int x, int y, t_env *env );
#endif
