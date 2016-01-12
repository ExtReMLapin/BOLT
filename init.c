/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:07:38 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/11 17:07:41 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "minilibx_macos/mlx.h"
int main()
{
	void *mlx;
	void *win;
	ft_putstr("REMOVE KEBAB MY FRIddddEND\n");
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400,400,"OHHHHHH");

	int i = 0;
	while (i < 400)
	{
		mlx_pixel_put(mlx, win, i,50, 0x00FFFFFF);
		mlx_pixel_put(mlx, win, i,51, 0x00FFFFFF);
		mlx_pixel_put(mlx, win, i,52, 0x00FFFFFF);
		i++;
	}
		mlx_loop(mlx);
	while (1)
	{}

	return (1);
}