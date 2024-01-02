/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:07:57 by lray              #+#    #+#             */
/*   Updated: 2024/01/02 16:58:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_map
{
	int	width;
	int	height;
	int	map[24][24];
}	t_map;


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

typedef struct s_ctx
{
	void	*mlx;
	t_win	win;
	t_map	map;
}	t_ctx;

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

#endif
