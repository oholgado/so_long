/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation01_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:00:26 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 19:52:07 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"

void	ft_boo_ex(t_g *g)
{
	g->gl.boo_ex = g->gl.boo_ex * -1;
}

char	*ft_ex_animate(t_g *g)
{
	ft_boo_ex(g);
	if (g->obj.obj_q != 0)
	{
		if (g->gl.boo_ex == -1)
			g->ex.ex_ph = "sprites/exit.xpm";
		else
			g->ex.ex_ph = "sprites/exit_closed.xpm";
	}
	if (g->obj.obj_q == 0)
	{
		if (g->gl.boo_ex == -1)
			g->ex.ex_ph = "sprites/exit.xpm";
		else
			g->ex.ex_ph = "sprites/exit_opened.xpm";
	}
	return (g->ex.ex_ph);
}
