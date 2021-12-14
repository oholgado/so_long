/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:00:00 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 19:00:11 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_boo(t_g *g)
{
	g->gl.boo = g->gl.boo * -1;
}

char	*ft_pla_right(t_g *g)
{
	ft_boo(g);
	if (g->gl.boo == -1)
		g->pla.pla_ph = "sprites/pac01.xpm";
	else
		g->pla.pla_ph = "sprites/pac02.xpm";
	return (g->pla.pla_ph);
}

char	*ft_pla_left(t_g *g)
{
	ft_boo(g);
	if (g->gl.boo == -1)
		g->pla.pla_ph = "sprites/pac01_left.xpm";
	else
		g->pla.pla_ph = "sprites/pac02_left.xpm";
	return (g->pla.pla_ph);
}

char	*ft_pla_up(t_g *g)
{
	ft_boo(g);
	if (g->gl.boo == -1)
		g->pla.pla_ph = "sprites/pac01_up.xpm";
	else
		g->pla.pla_ph = "sprites/pac02_up.xpm";
	return (g->pla.pla_ph);
}

char	*ft_pla_down(t_g *g)
{
	ft_boo(g);
	if (g->gl.boo == -1)
		g->pla.pla_ph = "sprites/pac01_down.xpm";
	else
		g->pla.pla_ph = "sprites/pac02_down.xpm";
	return (g->pla.pla_ph);
}
