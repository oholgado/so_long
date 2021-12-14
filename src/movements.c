/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:19:18 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 19:45:39 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 
#include "../mlx/mlx.h"
#include <stdlib.h>

int	ft_moveup(t_g *g)
{
	if (g->map.map_0[g->pla.pla_row - 1][g->pla.pla_col] != '1')
	{
		if (g->map.map_0[g->pla.pla_row - 1][g->pla.pla_col] == 'C')
		{
			g->obj.obj_q--;
		}
		if (g->map.map_0[g->pla.pla_row - 1][g->pla.pla_col] == 'E')
		{
			if (g->obj.obj_q == 0)
			{
				mlx_destroy_window(g->gl.mlx, g->gl.win);
				exit (1);
			}
			else
				return (0);
		}
		g->map.map_0[g->pla.pla_row][g->pla.pla_col] = '0';
		g->map.map_0[g->pla.pla_row - 1][g->pla.pla_col] = 'P';
		g->pla.pla_row--;
	}
	else
		return (0);
	return (1);
}

int	ft_movedown(t_g *g)
{
	if (g->map.map_0[g->pla.pla_row + 1][g->pla.pla_col] != '1')
	{
		if (g->map.map_0[g->pla.pla_row + 1][g->pla.pla_col] == 'C')
		{
			g->obj.obj_q--;
		}
		if (g->map.map_0[g->pla.pla_row + 1][g->pla.pla_col] == 'E')
		{
			if (g->obj.obj_q == 0)
			{
				mlx_destroy_window(g->gl.mlx, g->gl.win);
				exit (1);
			}
			else
				return (0);
		}
		g->map.map_0[g->pla.pla_row][g->pla.pla_col] = '0';
		g->map.map_0[g->pla.pla_row + 1][g->pla.pla_col] = 'P';
		g->pla.pla_row++;
	}
	else
		return (0);
	return (1);
}

int	ft_moveleft(t_g *g)
{
	if (g->map.map_0[g->pla.pla_row][g->pla.pla_col - 1] != '1')
	{
		if (g->map.map_0[g->pla.pla_row][g->pla.pla_col - 1] == 'C')
		{
			g->obj.obj_q--;
		}
		if (g->map.map_0[g->pla.pla_row][g->pla.pla_col - 1] == 'E')
		{
			if (g->obj.obj_q == 0)
			{
				mlx_destroy_window(g->gl.mlx, g->gl.win);
				exit (1);
			}
			else
				return (0);
		}
		g->map.map_0[g->pla.pla_row][g->pla.pla_col] = '0';
		g->map.map_0[g->pla.pla_row][g->pla.pla_col - 1] = 'P';
		g->pla.pla_col--;
	}
	else
		return (0);
	return (1);
}

int	ft_moveright(t_g *g)
{
	if (g->map.map_0[g->pla.pla_row][g->pla.pla_col + 1] != '1')
	{
		if (g->map.map_0[g->pla.pla_row][g->pla.pla_col + 1] == 'C')
		{
			g->obj.obj_q--;
		}
		if (g->map.map_0[g->pla.pla_row][g->pla.pla_col + 1] == 'E')
		{
			if (g->obj.obj_q == 0)
			{
				mlx_destroy_window(g->gl.mlx, g->gl.win);
				exit (1);
			}
			else
				return (0);
		}
		g->map.map_0[g->pla.pla_row][g->pla.pla_col] = '0';
		g->map.map_0[g->pla.pla_row][g->pla.pla_col + 1] = 'P';
		g->pla.pla_col++;
	}
	else
		return (0);
	return (1);
}
