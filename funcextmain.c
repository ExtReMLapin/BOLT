/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcextmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:38:59 by pfichepo          #+#    #+#             */
/*   Updated: 2016/03/12 18:39:00 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

static unsigned int		hsv_to_rgb(double h, double s, double v)
{
	t_hsv	hsv;

	hsv.i = floor(h / 60);
	hsv.f = (h / 60) - hsv.i;
	hsv.l = v * (1 - s);
	hsv.m = v * (1 - hsv.f * s);
	hsv.n = v * (1 - (1 - hsv.f) * s);
	hsv.l *= 255;
	hsv.m *= 255;
	hsv.n *= 255;
	v *= 255;
	if (hsv.i == 0)
		return (((int)v << 16) + ((int)hsv.n << 8) + (int)hsv.l);
	else if (hsv.i == 1)
		return (((int)hsv.m << 16) + ((int)v << 8) + (int)hsv.l);
	else if (hsv.i == 2)
		return (((int)hsv.l << 16) + ((int)v << 8) + (int)hsv.n);
	else if (hsv.i == 3)
		return (((int)hsv.l << 16) + ((int)hsv.m << 8) + (int)v);
	else if (hsv.i == 4)
		return (((int)hsv.n << 16) + ((int)hsv.l << 8) + (int)v);
	else
		return (((int)v << 16) + ((int)hsv.l << 8) + (int)hsv.m);
}



static void drawmap3d(t_env *env)
{
	  double newRe, newIm, oldRe, oldIm;
	  double zoom = 1, moveX = 0, moveY = 0;
	  int color;
	  int h = env->h;
	  int w = env->w;

	  for(int y = 0; y < h; y++)
	  for(int x = 0; x < w; x++)
	  {
	    newRe = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
	    newIm = (y - h / 2) / (0.5 * zoom * h) + moveY;
	    int i;
	    for(i = 0; i < env->maxIterations; i++)
	    {
	      oldRe = newRe;
	      oldIm = newIm;
	      newRe = oldRe * oldRe - oldIm * oldIm + env->cRe;
	      newIm = 2 * oldRe * oldIm + env->cIm;
	      if((newRe * newRe + newIm * newIm) > 4) break;
	    }
	    if (i< env->maxIterations)
	    	color  = hsv_to_rgb(i % 256, i % 256, i % 256);
	    else 
	    	color = 0x000000;
	   fastmlx_pixel_put(env, x, y, color);
	  }
	  mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int				draw(t_env *env)
{
	if (!env->mlx)
		error("MLX IS NULL");
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->w, env->h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, \
		&env->size_line, &env->endian);
	drawmap3d(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}