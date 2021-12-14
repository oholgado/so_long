/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook01_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:54:15 by oholgado          #+#    #+#             */
/*   Updated: 2021/12/10 17:15:27 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long_bonus.h"
#include <stdlib.h>

void	ft_keycode_up(t_g *g)
{
	g->ex.ex_ph = ft_ex_animate(g);
	g->pla.pla_ph = ft_pla_up(g);
	g->gl.moves += ft_moveup(g);
	ft_colision(g);
	ft_enemy_down(g);
}

void	ft_keycode_left(t_g *g)
{
	g->ex.ex_ph = ft_ex_animate(g);
	g->pla.pla_ph = ft_pla_left(g);
	g->gl.moves += ft_moveleft(g);
	ft_colision(g);
	ft_enemy_right(g);
}

void	ft_keycode_right(t_g *g)
{
	g->ex.ex_ph = ft_ex_animate(g);
	g->pla.pla_ph = ft_pla_right(g);
	g->gl.moves += ft_moveright(g);
	ft_colision(g);
	ft_enemy_left(g);
}

void	ft_keycode_down(t_g *g)
{
	g->ex.ex_ph = ft_ex_animate(g);
	g->pla.pla_ph = ft_pla_down(g);
	g->gl.moves += ft_movedown(g);
	ft_colision(g);
	ft_enemy_up(g);
}
