/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:59:34 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 18:59:47 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	ft_colision(t_g *g)
{
	if (g->map.map_0[g->pla.pla_row][g->pla.pla_col] ==
			g->map.map_0[g->ene.ene_row][g->ene.ene_col])
	{
		mlx_destroy_window(g->gl.mlx, g->gl.win);
		exit (1);
	}
}

void	ft_create_enemy(t_g *g)
{
	g->map.map_0[(g->map.map_row / 3)][(g->map.map_col / 2)] = 'G';
	g->ene.ene_row = g->map.map_row / 3;
	g->ene.ene_col = g->map.map_col / 2;
}

void	ft_boo_enemy(t_g *g)
{
	g->ene.boo = g->ene.boo * -1;
}

char	*ft_animate_enemy(t_g *g)
{
	ft_boo_enemy(g);
	if (g->ene.boo == -1)
		g->ene.ene_ph = "sprites/ghost01.xpm";
	else
		g->ene.ene_ph = "sprites/ghost02.xpm";
	return (g->ene.ene_ph);
}
