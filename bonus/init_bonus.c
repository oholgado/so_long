/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:53:42 by oholgado          #+#    #+#             */
/*   Updated: 2021/12/10 17:17:36 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"
#include <stdio.h>

void	ft_init_images(t_g *g)
{
	g->pla.pla_ph = "sprites/pac01.xpm";
	g->ex.ex_ph = "sprites/exit_closed.xpm";
	g->obj.obj_ph = "sprites/peanuts.xpm";
	g->wal.wal_ph = "sprites/bck_zoo.xpm";
	g->bck.bck_ph = "sprites/bck_green.xpm";
	g->ene.ene_ph = "sprites/ghost03.xpm";
}

void	ft_file_images(t_g *g)
{
	g->bck.img = mlx_xpm_file_to_image(g->gl.mlx,
			g->bck.bck_ph, &g->gl.im_w, &g->gl.im_h);
	g->obj.img = mlx_xpm_file_to_image(g->gl.mlx,
			g->obj.obj_ph, &g->gl.im_w, &g->gl.im_h);
	g->wal.img = mlx_xpm_file_to_image(g->gl.mlx,
			g->wal.wal_ph, &g->gl.im_w, &g->gl.im_h);
	g->pla.img = mlx_xpm_file_to_image(g->gl.mlx,
			g->pla.pla_ph, &g->gl.im_w, &g->gl.im_h);
	g->ex.img = mlx_xpm_file_to_image(g->gl.mlx,
			g->ex.ex_ph, &g->gl.im_w, &g->gl.im_h);
	g->ene.img = mlx_xpm_file_to_image(g->gl.mlx,
			g->ene.ene_ph, &g->gl.im_w, &g->gl.im_h);
}

void	ft_put_sprites(t_g *g, char c)
{
	mlx_put_image_to_window(g->gl.mlx, g->gl.win,
		g->bck.img, g->gl.im_x * 50, g->gl.im_y * 50);
	if (c == '1')
		mlx_put_image_to_window(g->gl.mlx, g->gl.win,
			g->wal.img, g->gl.im_x * 50, g->gl.im_y * 50);
	else if (c == 'C')
		mlx_put_image_to_window(g->gl.mlx, g->gl.win,
			g->obj.img, g->gl.im_x * 50, g->gl.im_y * 50);
	else if (c == 'P')
		mlx_put_image_to_window(g->gl.mlx, g->gl.win,
			g->pla.img, g->gl.im_x * 50, g->gl.im_y * 50);
	else if (c == 'E')
		mlx_put_image_to_window(g->gl.mlx, g->gl.win,
			g->ex.img, g->gl.im_x * 50, g->gl.im_y * 50);
	else if (c == 'G')
		mlx_put_image_to_window(g->gl.mlx, g->gl.win,
			g->ene.img, g->gl.im_x * 50, g->gl.im_y * 50);
	mlx_string_put(g->gl.mlx, g->gl.win, (((g->map.map_col * 50) / 2) - 80),
		(g->map.map_row * 50 + 20), 0xFFFFFF, "MOVES: ");
	mlx_string_put(g->gl.mlx, g->gl.win, ((g->map.map_col * 50) / 2),
		(g->map.map_row * 50 + 20), 0xFFFFFF, ft_itoa(g->gl.moves));
}

void	ft_draw_map(t_g *g)
{
	int	row;
	int	col;

	row = 0;
	mlx_clear_window(g->gl.mlx, g->gl.win);
	while (row < g->map.map_row)
	{
		col = 0;
		while (col < g->map.map_col)
		{
			g->gl.im_y = row;
			g->gl.im_x = col;
			ft_put_sprites(g, g->map.map_0[row][col]);
			col++;
		}
		row++;
	}
}

void	ft_game_handler(t_g *g)
{
	g->gl.moves = 0;
	g->gl.boo = -1;
	g->gl.boo_ex = -1;
	g->ene.boo = -1;
	g->gl.im_w = 50;
	g->gl.im_h = 50;
	g->gl.mlx = mlx_init();
	ft_init_images(g);
	ft_file_images(g);
	g->gl.win = mlx_new_window(g->gl.mlx, (g->map.map_col * 50),
			(g->map.map_row * 50) + 50, "A VISIT SO LONG");
	ft_draw_map(g);
	mlx_hook(g->gl.win, 2, 1L << 0, ft_keyhook, g);
	mlx_hook(g->gl.win, 17, 0L << 0, ft_close_window, g);
	mlx_loop(g->gl.mlx);
}
