/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:44:13 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 23:18:51 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
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
# include "parsing.h"
# include "move.h"

# define WIN_NAME "cub3D"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

#endif
