/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:48:53 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 19:44:46 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_data_player(t_g *g, int row, int col)
{
	g->pla.pla_q += 1;
	g->pla.pla_row = row;
	g->pla.pla_col = col;
}

static void	ft_data_exit(t_g *g, int row, int col)
{
	g->ex.ex_q += 1;
	g->ex.ex_row = row;
	g->ex.ex_col = col;
}

void	ft_get_data(t_g *g)
{
	int		row;
	int		col;

	row = 0;
	while (row < g->map.map_row)
	{
		col = 0;
		while (col < g->map.map_col)
		{
			if (g->map.map_0[row][col] == 'P')
				ft_data_player(g, row, col);
			if (g->map.map_0[row][col] == 'C')
				g->obj.obj_q += 1;
			if (g->map.map_0[row][col] == 'E')
				ft_data_exit(g, row, col);
			col++;
		}
	row++;
	}
}
