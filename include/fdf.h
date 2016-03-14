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
# define OFFSETBOX 100
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
	int				mapy;
	int				mapx;
	int				offsetx;
	int				offsety;
	clock_t			timestart;
	clock_t			timeend;
	clock_t			time;
	unsigned int	rendermode;
	int				maxz;
	int				minz;
	int				zoom;
}					t_env;

unsigned long		creatergb(int r, int g, int b);
int					fastmlx_pixel_put(t_env *env, int x, int y, int color);
void				fdf_putline(t_env *e, t_point *o, t_point *d);
void				ft_singlepointtrans(t_env *e, t_point *p);
void				ft_transform2d(t_env *e);
int					tblmax(int **tbl, int choice);
t_point				*mapsize(t_env *env);
t_point				*mapmin(t_env *env);
t_point				*mapmax(t_env *env);
void				checkread(char *s);
int					draw(t_env *env);
void				goodsize(t_env *env);
void				drawbox(int x , int y, int w, int h, int c, t_env *env);
void				mapsize2(t_env *env);
void				calczoom(t_env *env);
void				drawmap2d(t_env *env);
#endif
