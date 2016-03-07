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
#define	FDF_H
#include <math.h>
#include "../libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_angle
{
	int				yaw;
	int				pitch;
	int				roll;
}					t_angle;


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_point			*grid;
	void			*img;
	int				w;
	int				h;
	float			zoom;
	int				fov;
	t_point			campos;
	t_angle			camangle;
	float 			factor;
	int				mapy;
	int				mapx;
	int				offsetx;
	int				offsety;

}					t_env;


unsigned long		createRGB(int r, int g, int b);
void				drawbox(int x , int y, int w, int h, int c, t_env *env);
int					fastmlx_pixel_put(t_env *env, int x, int y, int color);
void				fdf_putline(t_env *e, t_point *o, t_point *d);
void				ft_singlepointtrans(t_env *e, t_point *p);
void				ft_transform2d(t_env *e);
int					tblmax(int **tbl, int choice);
t_point				*mapsize(t_env *env);
t_point				*mapmin(t_env *env);
void				checkread(char *s);
#endif
