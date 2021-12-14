/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:09:38 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 18:46:26 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>

typedef struct s_player
{
	void	*img;
	char	*pla_ph;
	int		pla_row;
	int		pla_col;
	int		pla_q;
}	t_player;

typedef struct s_exit
{
	void	*img;
	char	*ex_ph;
	int		ex_row;
	int		ex_col;
	int		ex_q;
}	t_exit;

typedef struct s_obj
{
	void	*img;
	char	*obj_ph;
	int		obj_q;
}	t_obj;

typedef struct s_bck
{
	void	*img;
	char	*bck_ph;

}	t_bck;

typedef struct s_walls
{
	void	*img;
	char	*wal_ph;
}	t_walls;

typedef struct s_map
{
	char	**map_0;
	char	*map_file;
	int		map_row;
	int		map_col;
}	t_map;

typedef struct s_global
{
	void	*mlx;
	void	*win;
	int		im_w;
	int		im_h;
	int		moves;
	int		im_x;
	int		im_y;
}	t_global;

typedef struct s_g
{
	t_global	gl;
	t_player	pla;
	t_exit		ex;
	t_obj		obj;
	t_bck		bck;
	t_walls		wal;
	t_map		map;
}	t_g;

void	ft_map_count(t_g *g);	
void	ft_map_malloc(t_g *g);
void	ft_map_write(t_g *g);;
void	ft_error_walls(void);
void	ft_check_walls(t_g *g);
void	ft_error_objects(t_g *g);
void	ft_map_read(t_g *g);
void	ft_error_elements(char buff);
void	ft_get_data(t_g *g);
void	ft_init_variables(t_g *g);
void	ft_init_images(t_g *g);
void	ft_put_sprites(t_g *g, char c);
void	ft_draw_map(t_g *g);
void	ft_game_handler(t_g *g);
int		ft_keyhook(int keycode, t_g *g);
int		ft_close_window(t_g *g);
int		ft_moveup(t_g *g);
int		ft_movedown(t_g *g);
int		ft_moveleft(t_g *g);
int		ft_moveright(t_g *g);
void	ft_file_images(t_g *g);
void	ft_destroy_images(t_g *g);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);
int		ft_strlen(char *str);

#endif
