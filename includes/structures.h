/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:07:57 by lray              #+#    #+#             */
/*   Updated: 2024/01/06 08:46:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_veci
{
	int	x;
	int	y;
}	t_veci;

typedef struct s_ray
{
	double	camera_x;
	t_vec	dir;
	t_veci	map;
	t_vec	side_dist;
	t_vec	delta_dist;
	double	perp_wall_dist;
	t_veci	step;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_map
{
	int	width;
	int	height;
	int	map[24][24];
}	t_map;

typedef struct s_player
{
	t_vec	pos;
	t_vec	dir;
	t_vec	cam;
}	t_player;

typedef struct s_win
{
	int		width;
	int		height;
	char	*name;
	void	*win;
	void	*mlx;
}	t_win;

typedef struct s_win_params
{
	void	*mlx;
	int		width;
	int		height;
	char	*name;
}	t_win_params;

typedef struct s_image
{
	void	*data;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_ctx
{
	void		*mlx;
	t_win		win;
	t_map		map;
	t_player	player;
	t_image		*background;
}	t_ctx;

#endif
