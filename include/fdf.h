/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:20:45 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/14 13:00:49 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define OFFSETBOX 100
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49
# include <math.h>
# include "../libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_point			*grid;
	int				w;
	int				h;
	float			factor;
	void			*img;
	int				mapy;
	int				mapx;
	int				offsetx;
	int				offsety;
	clock_t			timestart;
	clock_t			timeend;
	clock_t			time;
	double			frametime;
	unsigned int	rendermode;
	int				maxz;
	int				minz;
	int				zoom;
	int				c;
	int				bpp;
	char			*data;
	int				size_line;
	int				endian;
	int				up;
	int				down;
	int				left;
	int				spkey;
	int				right;
}					t_env;

typedef struct		s_box
{
	int				x;
	int				y;
	int				w;
	int				h;
	int				c;
}					t_box;

unsigned long		creatergb(int r, int g, int b);
int					fastmlx_pixel_put(t_env *env, int x, int y, int color);
void				fdf_putline(t_env *e, t_point *o, t_point *d);
void				ft_singlepointtrans(t_env *e, t_point *p);
void				ft_transform2d(t_env *e);
int					tblmax(int **tbl, int choice);
t_point				*mapsize(t_env *env);
t_point				*mapmin(t_env *env);
t_point				*mapmax(t_env *env);
void				checkread(char *s, t_env *env);
int					draw(t_env *env);
void				goodsize(t_env *env);
void				drawbox(t_box *box, t_env *env);
void				mapsize2(t_env *env);
void				calczoom(t_env *env);
void				drawmap2d(t_env *env);
void				movething(t_env *env, char c, int dest);
int					hook_loop(t_env *env);
int					key_release(int keycode, t_env *env);
int					key_press(int keycode, t_env *env);
int 				close_hook(t_env *env);
#endif
