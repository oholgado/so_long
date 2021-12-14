/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:55:27 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 18:58:37 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"

void	ft_enemy_up(t_g *g)
{
	if (g->map.map_0[g->ene.ene_row - 1][g->ene.ene_col] == '0')
	{
		g->map.map_0[g->ene.ene_row][g->ene.ene_col] = '0';
		g->map.map_0[g->ene.ene_row - 1][g->ene.ene_col] = 'G';
		g->ene.ene_ph = ft_animate_enemy(g);
		g->ene.ene_row--;
	}
	else
		ft_enemy_left(g);
}

void	ft_enemy_down(t_g *g)
{
	if (g->map.map_0[g->ene.ene_row + 1][g->ene.ene_col] == '0')
	{
		g->map.map_0[g->ene.ene_row][g->ene.ene_col] = '0';
		g->map.map_0[g->ene.ene_row + 1][g->ene.ene_col] = 'G';
		g->ene.ene_ph = ft_animate_enemy(g);
		g->ene.ene_row++;
	}
	else
		ft_enemy_right(g);
}

void	ft_enemy_left(t_g *g)
{
	if (g->map.map_0[g->ene.ene_row][g->ene.ene_col - 1] == '0')
	{
		g->map.map_0[g->ene.ene_row][g->ene.ene_col] = '0';
		g->map.map_0[g->ene.ene_row][g->ene.ene_col - 1] = 'G';
		g->ene.ene_ph = ft_animate_enemy(g);
		g->ene.ene_col--;
	}
	else
		ft_enemy_down(g);
}

void	ft_enemy_right(t_g *g)
{
	if (g->map.map_0[g->ene.ene_row][g->ene.ene_col + 1] == '0')
	{
		g->map.map_0[g->ene.ene_row][g->ene.ene_col] = '0';
		g->map.map_0[g->ene.ene_row][g->ene.ene_col + 1] = 'G';
		g->ene.ene_ph = ft_animate_enemy(g);
		g->ene.ene_col++;
	}
	else
		ft_enemy_up(g);
}
