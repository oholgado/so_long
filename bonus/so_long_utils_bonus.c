/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:22:09 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 19:22:19 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_map_count(t_g *g)
{
	char	buffer;
	int		fd;

	fd = open(g->map.map_file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nBad file descriptor.");
		exit (1);
	}
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
			break ;
		g->map.map_col++;
	}
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n' || buffer == '\0')
			g->map.map_row++;
	}
	g->map.map_row += 2;
	close(fd);
}

void	ft_map_malloc(t_g *g)
{
	int		i;
	char	**buffer;

	i = 0;
	buffer = malloc(sizeof(char *) * (g->map.map_row));
	if (!buffer)
		return ;
	while (i < g->map.map_row)
	{
		buffer[i] = malloc(g->map.map_col);
		if (!buffer[i])
			return ;
		i++;
	}
	g->map.map_0 = buffer;
}

void	ft_map_write(t_g *g)
{
	int		row;
	int		col;
	int		fd;
	char	buff;

	row = 0;
	col = 0;
	fd = open(g->map.map_file, O_RDONLY);
	while (read(fd, &buff, 1) != 0)
	{
		if (buff != '\n')
		{
			g->map.map_0[row][col] = buff;
			col++;
		}
		if (buff == '\n')
		{
			row++;
			col = 0;
		}
	}
	close (fd);
}
