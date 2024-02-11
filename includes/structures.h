/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:07:57 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 20:16:26 by lray             ###   ########.fr       */
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
	int		draw_point[2];
	int		line_height;
	double	wall_x;
}	t_ray;

typedef struct s_map
{
	t_veci	map_size;
	char	**data;
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

typedef struct s_color
{
	unsigned int	rgb_floor;
	unsigned int	rgb_ceiling;
}	t_color;

typedef struct s_texture
{
	char	*no_texture_path;
	char	*so_texture_path;
	char	*we_texture_path;
	char	*ea_texture_path;
}	t_texture;

typedef struct s_ctx
{
	void		*mlx;
	t_win		win;
	t_map		*map;
	t_player	player;
	t_image		*textures[5];
	t_texture	textures_path;
	t_color		color;
}	t_ctx;

typedef struct s_parsing_data
{
	t_color		*color;
	t_texture	*texture;
	t_map		*map;
}	t_parsing_data;

#endif
