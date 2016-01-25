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

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_point			*grid;
	void			*img;
	int				w;
	int				h;
	float			zoom;

}					t_env;


unsigned long		createRGB(int r, int g, int b);
void				drawbox(int x , int y, int w, int h, int c, t_env *env);
int					fastmlx_pixel_put(t_env *env, int x, int y, int color);

#endif
