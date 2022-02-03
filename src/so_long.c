/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:36:43 by oholgado          #+#    #+#             */
/*   Updated: 2021/12/10 18:42:34 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

void	ft_init_variables(t_g *g)
{
	g->pla.pla_q = 0;
	g->obj.obj_q = 0;
	g->ex.ex_q = 0;
	g->pla.pla_row = 0;
	g->pla.pla_col = 0;
}

void	ft_program_flow(t_g *g)
{
	ft_map_count(g);
	ft_map_malloc(g);
	ft_map_write(g);
	ft_map_read(g);
	ft_check_walls(g);
	ft_init_variables(g);
	ft_get_data(g);
	ft_error_objects(g);
	ft_game_handler(g);
}

int	main(int argc, char **argv)
{
	t_g		g;
	char	*boo;

	if (argc == 2)
	{
		boo = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
		if (boo == NULL)
		{
			printf("Error\nBad extension file");
			exit (1);
		}
		g.map.map_file = argv[1];
		ft_program_flow(&g);
	}
	else
		printf("Error\nExecute ./so_long map_file.ber, please.");
	return (0);
}
