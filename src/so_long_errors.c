/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:26:38 by oholgado          #+#    #+#             */
/*   Updated: 2021/12/03 11:22:47 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_error_walls(void)
{
	printf("Error\nThe map is open");
	exit (0);
}

void	ft_check_walls(t_g *g)
{
	int	row;
	int	col;

	row = 0;
	while (row < g->map.map_row)
	{
		col = 0;
		while (col < g->map.map_col)
		{
			if (g->map.map_0[0][col] != '1')
				ft_error_walls();
			if (g->map.map_0[row][0] != '1')
				ft_error_walls();
			if (g->map.map_0[row][g->map.map_col - 1] != '1')
				ft_error_walls();
			if (g->map.map_0[g->map.map_row - 1][col] != '1')
				ft_error_walls();
			col++;
		}
		row++;
	}
}

void	ft_error_objects(t_g *g)
{
	if (g->obj.obj_q < 1)
	{
		printf("Error\nThere is nothing to collect");
		exit (1);
	}
	if (g->ex.ex_q < 1)
	{
		printf("Error\nThere is not exit");
		exit (1);
	}
	if (g->ex.ex_q > 1)
	{
		printf("Error\nToo many exits");
		exit (1);
	}
	if (g->pla.pla_q > 1)
	{
		printf("Error\nToo many players");
		exit (1);
	}
	if (g->pla.pla_q < 1)
	{
		printf("Error\nThere is not player");
		exit (1);
	}
}

void	ft_error_elements(char buff)
{
	if (buff != '1' && buff != 'C' && buff != 'P' && buff != '0'
		&& buff != 'E' && buff != '\n')
	{		
		printf("Error\nInsert a valid map, please");
		exit (1);
	}
}

void	ft_map_read(t_g *g)
{
	int	row;
	int	col;

	row = 0;
	while (row < g->map.map_row)
	{
		col = 0;
		while (col < g->map.map_col)
		{
			ft_error_elements(g->map.map_0[row][col]);
			col++;
		}
		row++;
	}
}
