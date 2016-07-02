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
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# define mapWidth 24
# define mapHeight 24
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363


typedef struct	s_w3d
{
	double			cameraX;
	double			rayPosX;
	double			rayPosY;
	double			rayDirX;
	double			rayDirY;
	int				x;
	int				mapX;
	int				mapY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	int				color;
}				t_w3d;

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
	double			posX; //x and y start position
	double			posY ;
	double			dirX;
	double			dirY; //initial direction vector
	double			planeX ;
	double			planeY; //the 2d raycaster version of camera plane				
	clock_t			time; //time of current frame
	clock_t			oldtime; //time of previous frame
	double			frametime;
	int				**worldMap;
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
int 				mousekey( int x, int y, t_env *env );
int 				mousebutton( int button, int x, int y, t_env *env );
int					hook_loop(t_env *env);
int					key_release(int keycode, t_env *env);
int					key_press(int keycode, t_env *env);
#endif
