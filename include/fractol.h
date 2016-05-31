/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:20:45 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/14 13:20:47 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_julia
{
	long double		nr;
	long double		ni;
	long double		orr;
	long double		oi;
	int				h;
	int				w;
	int				x;
	int				y;
	int				i;
}					t_julia;

typedef struct		s_mandel
{
	long double		nre;
	long double		ni;
	long double		ore;
	long double		oi;
	long double		pi;
	long double		pr;
	int				h;
	int				w;
	int				x;
	int				y;
	int				i;
}					t_mandel;

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
	int				maxiterations;
	double			cre;
	double			cim;
	double			oy;
	double			ox;
	double			zm;
	t_julia			*ja;
	t_mandel		*md;
}					t_env;

typedef struct		s_hsv
{
	long double		i;
	long double		f;
	long double		l;
	long double		m;
	long double		n;
}					t_hsv;

void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				error(char const *s);
void				errornohalt(char const *s);
unsigned long		creatergb(int r, int g, int b);
int					fastmlx_pixel_put(t_env *env, int x, int y, int color);
int					draw(t_env *env);
void				goodsize(t_env *env);
int					hookkey(int keycode, t_env *env);
int					mousekey(int x, int y, t_env *env);
unsigned int		hsv(long double v, t_env *env, int i);
void				drawjulia(t_env *e);
void				drawmend(t_env *e);
int					strequal(char *str1, char *str2);
int					mousebutton(int button, int x, int y, t_env *env);
void				drawmend2(t_env *e);

#endif
