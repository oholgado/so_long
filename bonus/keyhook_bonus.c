/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:54:50 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 19:02:22 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long_bonus.h"
#include <stdlib.h>

int	ft_close_window(t_g *g)
{
	mlx_destroy_window(g->gl.mlx, g->gl.win);
	exit (0);
	return (0);
}

void	ft_destroy_images(t_g *g)
{
	mlx_destroy_image(g->gl.mlx, g->pla.img);
	mlx_destroy_image(g->gl.mlx, g->ex.img);
	mlx_destroy_image(g->gl.mlx, g->obj.img);
	mlx_destroy_image(g->gl.mlx, g->wal.img);
	mlx_destroy_image(g->gl.mlx, g->bck.img);
	mlx_destroy_image(g->gl.mlx, g->ene.img);
}

int	ft_keyhook(int keycode, t_g *g)
{
	if (keycode == 13)
	{
		ft_keycode_up(g);
	}
	else if (keycode == 0)
	{
		ft_keycode_left(g);
	}
	else if (keycode == 2)
	{	
		ft_keycode_right(g);
	}
	else if (keycode == 1)
	{
		ft_keycode_down(g);
	}
	ft_destroy_images(g);
	ft_file_images(g);
	ft_draw_map(g);
	if (keycode == 53)
		ft_close_window(g);
	return (0);
}
