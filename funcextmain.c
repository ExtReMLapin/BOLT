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

static float HSV(int h, int s, int v)
{
    if (s <= 0)
    	 return creatergb(v,v,v);
     h = h/256*6;
    s = s/255;
    v =  v/255;
    float c = v*s;
    float x = (1-abs((h%2)-1))*c;
    float m = (v-c);
    float r = 0;
    float g = 0;
    float b = 0;
    if (h < 1) 
    { 
    	r = c;
    	g = x;
    	b = 0;
    }
    else
    {
    	if (h < 2) { return creatergb((x+m)*255,(c+m)*255,(0+m)*255);}
	    if (h < 3) { return creatergb((0+m)*255,(c+m)*255,(x+m)*255);}
	    if (h < 4) { return creatergb((0+m)*255,(x+m)*255,(c+m)*255);}
	    if (h < 5) { return creatergb((x+m)*255,(0+m)*255,(c+m)*255);}
	    return creatergb((c+m)*255,(0+m)*255,(x+m)*255);
    }
    return creatergb((r+m)*255,(g+m)*255,(b+m)*255);
}


static void drawmap3d(t_env *env)
{


	  //each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
	  double cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
	  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
	  double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
	  int color; //the RGB color value for the pixel
	  int h = env->h;
	  int w = env->w;
	  //pick some values for the constant c, this determines the shape of the Julia Set
	  cIm = 0.27015;

	  //loop through every pixel
	  for(int y = 0; y < h; y++)
	  for(int x = 0; x < w; x++)
	  {
	    //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
	    newRe = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
	    newIm = (y - h / 2) / (0.5 * zoom * h) + moveY;
	    //i will represent the number of iterations
	    int i;
	    //start the iteration process
	    for(i = 0; i < env->maxIterations; i++)
	    {
	      //remember value of previous iteration
	      oldRe = newRe;
	      oldIm = newIm;
	      //the actual iteration, the real and imaginary part are calculated
	      newRe = oldRe * oldRe - oldIm * oldIm + env->cRe;
	      newIm = 2 * oldRe * oldIm + cIm;
	      //if the point is outside the circle with radius 2: stop
	      if((newRe * newRe + newIm * newIm) > 4) break;
	    }
	    //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
	    color = HSV(i % 256, 255, 255 * (i < env->maxIterations));
	    //draw the pixel
	   fastmlx_pixel_put(env, x, y, color);
	  }
	  mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);

}

static void		drawinfo(t_env *env)
{
	char		buffer[255];
	char		buffer2[255];
	double		time1;
	double		time2;
	char		*a;

	a = ft_itoa(pointsnb(env->grid));
	time1 = (double)(clock() - env->time);
	time2 = (double)(env->timeend - env->timestart);
	mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF, "Points :");
	mlx_string_put(env->mlx, env->win, 110, 10, 0xFFFFFF, a);
	sprintf(buffer, "%.4f", time1 / 1000000);
	sprintf(buffer2, "%.3f", time2 / 1000000);
	mlx_string_put(env->mlx, env->win, 10, 40, 0xFFFFFF, "Sec to draw :");
	mlx_string_put(env->mlx, env->win, 194, 40, 0xFFFFFF, buffer);
	mlx_string_put(env->mlx, env->win, 10, 70, 0xFFFFFF, "Sec to proc :");
	mlx_string_put(env->mlx, env->win, 194, 70, 0xFFFFFF, buffer2);
}

int				draw(t_env *env)
{
	if (!env->mlx)
		error("MLX IS NULL");
	env->time = clock();
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->w, env->h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, \
		&env->size_line, &env->endian);
	ft_putstr("Cleared\n");
	if (env->rendermode == 3)
		drawmap3d(env);
	else
		drawmap2d(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	drawinfo(env);
	return (1);
}

static void		lastopgoodsize(t_env *env)
{
	t_point *size;

	ft_transform2d(env);
	size = mapmin(env);
	env->offsetx = -(size->x);
	env->offsety = -(size->y);
	ft_transform2d(env);
	size = mapmax(env);
	env->offsetx = env->offsetx + (env->w - size->x) / 2;
	env->offsety = env->offsety + (env->h - size->y) / 2;
	ft_transform2d(env);
}

void			goodsize(t_env *env)
{
	t_point		*size;
	double		old;

	old = env->factor;
	ft_transform2d(env);
	while (1)
	{
		size = mapsize(env);
		if (((env->w - size->x) < 0) || ((env->h - size->y) < 0))
		{
			if (old == 0.01)
				errornohalt("Can't find good size");
			env->factor = old;
			break ;
		}
		if (((env->w - size->x) < 100) || ((env->h - size->y) < 100))
			break ;
		old = env->factor;
		env->factor += 0.0001;
		ft_transform2d(env);
	}
	lastopgoodsize(env);
}
