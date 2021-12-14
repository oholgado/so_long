/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:49:21 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 20:13:59 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

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
}

int	ft_keyhook(int keycode, t_g *g)
{
	if (keycode == 13)
		g->gl.moves += ft_moveup(g);
	else if (keycode == 0)
		g->gl.moves += ft_moveleft(g);
	else if (keycode == 2)
		g->gl.moves += ft_moveright(g);
	else if (keycode == 1)
		g->gl.moves += ft_movedown(g);
	printf("MOVES : %d\n", g->gl.moves);
	ft_destroy_images(g);
	ft_file_images(g);
	ft_draw_map(g);
	if (keycode == 53)
		ft_close_window(g);
	return (0);
}
