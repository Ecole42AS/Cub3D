/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:44:13 by lray              #+#    #+#             */
/*   Updated: 2024/01/09 11:05:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define DISPLAY_WIDTH 800
# define DISPLAY_HEIGHT 600

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../minilibx/linux/mlx.h"

# include "structures.h"
# include "mlx_utils.h"
# include "colors.h"
# include "events.h"
# include "ctx.h"
# include "win.h"
# include "gameloop.h"
# include "player.h"
# include "ray.h"
# include "move.h"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_parsing
{
	char	**parsed_lines;
}			t_parsing;

char	*gnl_unempty(int fd);
int		open_file(char *file);

#endif
