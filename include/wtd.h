/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:20:45 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/05 11:38:39 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WTD_H
# define WTD_H
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# define MAPWIDTH 19
# define MAPHEIGHT 19
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define BUFF_SIZE 16384

typedef struct		s_slist
{
	char			c;
	struct s_slist	*next;
	int				fd;
}					t_slist;

typedef struct		s_w3d
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
}					t_w3d;

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
	int				worldmap[MAPWIDTH][MAPHEIGHT];
	int				up;
	int				down;
	int				left;
	int				right;
	int				**map;
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
void				emptymap(t_env *env);
void				draw2dpt3(t_w3d *w3d, t_env *env);
void				draw2dpt2(t_w3d *w3d, t_env *env);
void				draw2dpt1(t_w3d *w3d);
void				draw2dpt0(t_env *env, t_w3d *w3d);
int					close_hook(t_env *env);
#endif
