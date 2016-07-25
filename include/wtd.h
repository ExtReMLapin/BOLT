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

#ifndef WTD_H
# define WTD_H
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct	s_w3d
{
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				x;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
}				t_w3d;

typedef struct		s_hsv
{
	long double		i;
	long double		f;
	long double		l;
	long double		m;
	long double		n;
}					t_hsv;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
	void			*img;
	int				bpp;
	char			*data;
	int				size_line;
	int				endian;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	clock_t			time;
	clock_t			oldtime;
	double			frametime;
	int				**worldmap;
	int				up;
	int				down;
	int				left;
	int				right;
	t_w3d			*w3d;
}					t_env;

void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				error(char const *s);
void				errornohalt(char const *s);
unsigned long		creatergb(int r, int g, int b);
int					fastmlx_pixel_put(t_env *env, int x, int y, int color);
int					draw(t_env *env);
int					mousekey(int x, int y, t_env *env);
int					mousebutton(int button, int x, int y, t_env *env);
int					hook_loop(t_env *env);
int					key_release(int keycode, t_env *env);
int					key_press(int keycode, t_env *env);
unsigned int		hsv(long double v);
void				verlineex(t_env *env, int x, int col);
#endif
