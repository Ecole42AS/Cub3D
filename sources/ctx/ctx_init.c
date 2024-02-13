/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:51:50 by lray              #+#    #+#             */
/*   Updated: 2024/02/13 13:07:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_win(t_ctx *ctx);
static int	init_map(t_ctx *ctx);
static void	init_player(t_ctx *ctx);
static void	init_texture(t_ctx *ctx);

int	ctx_init(t_ctx *ctx, int win_width, int win_height, char *win_name)
{
	ctx->mlx = NULL;
	init_win(ctx);
	if (!init_map(ctx))
	{
		ft_putstr_fd("Error during map initialization\n", 2);
		return (0);
	}
	init_player(ctx);
	init_texture(ctx);
	ctx->win.width = win_width;
	ctx->win.height = win_height;
	ctx->win.name = win_name;
	ctx->textures_path.no_texture_path = NULL;
	ctx->textures_path.so_texture_path = NULL;
	ctx->textures_path.ea_texture_path = NULL;
	ctx->textures_path.we_texture_path = NULL;
	ctx->textures[0] = NULL;
	ctx->textures[1] = NULL;
	ctx->textures[2] = NULL;
	ctx->textures[3] = NULL;
	ctx->textures[4] = NULL;
	ctx->color.rgb_floor = 0;
	ctx->color.rgb_ceiling = 0;
	ft_memset(&ctx->keys, 0, sizeof(t_keys));
	return (1);
}

static int	init_map(t_ctx *ctx)
{
	ctx->map = malloc(sizeof(t_map));
	if (!ctx->map)
	{
		ft_putstr_fd("Malloc failed\n", 2);
		return (0);
	}
	ctx->map->map_size.x = 0;
	ctx->map->map_size.y = 0;
	ctx->map->data = NULL;
	return (1);
}

static void	init_win(t_ctx *ctx)
{
	ctx->win.width = 0;
	ctx->win.height = 0;
	ctx->win.win = NULL;
	ctx->win.name = NULL;
	ctx->win.mlx = NULL;
}

static void	init_player(t_ctx *ctx)
{
	ctx->player.cam.x = 0;
	ctx->player.cam.y = 0;
	ctx->player.dir.x = 0;
	ctx->player.dir.y = 0;
	ctx->player.pos.x = 0;
	ctx->player.pos.y = 0;
}

static void	init_texture(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < 5)
		ctx->textures[i++] = NULL;
}
