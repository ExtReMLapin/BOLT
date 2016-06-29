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
# define mapWidth 24
# define mapHeight 24

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
	double			time; //time of current frame
	double			oldTime; //time of previous frame
	int				**worldMap;
}					t_env;

typedef struct	s_hsv
{
	long double	i;
	long double	f;
	long double	l;
	long double	m;
	long double	n;
}				t_hsv;

void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				error(char const *s);
void				errornohalt(char const *s);
unsigned long		creatergb(int r, int g, int b);
int					fastmlx_pixel_put(t_env *env, int x, int y, int color);
int					draw(t_env *env);
int					hookkey(int keycode, t_env *env);
int 				mousekey( int x, int y, t_env *env );
int					strequal(char *str1, char *str2);
int 				mousebutton( int button, int x, int y, t_env *env );
#endif
