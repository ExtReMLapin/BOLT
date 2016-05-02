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

static int HSV(int h, int s, int v)
{
    if (s <= 0)
    	 return creatergb(v,v,v);
     h = h/256*6;
    s = s/255;
    v =  v/255;
    float c = v*s;
    float x = (1-abs((h%2)-1))*c;
    float m = (v-c);
    if (h < 1) { return creatergb((c+m)*255,(x+m)*255,(0+m)*255);}
    if (h < 2) { return creatergb((x+m)*255,(c+m)*255,(0+m)*255);}
	if (h < 3) { return creatergb((0+m)*255,(c+m)*255,(x+m)*255);}
	if (h < 4) { return creatergb((0+m)*255,(x+m)*255,(c+m)*255);}
	if (h < 5) { return creatergb((x+m)*255,(0+m)*255,(c+m)*255);}
	return creatergb((c+m)*255,(0+m)*255,(x+m)*255);
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
	    	color  = HSV(i % 256, 255, 255);
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