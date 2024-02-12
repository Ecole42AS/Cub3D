/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 04:21:34 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 18:33:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	make_background(t_ctx *ctx, unsigned int c1, unsigned int c2);

int	ctx_init_textures(t_ctx *ctx)
{
	ctx->textures[0] = img_create(ctx->mlx, ctx->win.width, ctx->win.height);
	make_background(ctx, ctx->color.rgb_floor, ctx->color.rgb_ceiling);
	ctx->textures[1] = img_load(ctx->mlx, ctx->textures_path.no_texture_path);
	ctx->textures[2] = img_load(ctx->mlx, ctx->textures_path.so_texture_path);
	ctx->textures[3] = img_load(ctx->mlx, ctx->textures_path.ea_texture_path);
	ctx->textures[4] = img_load(ctx->mlx, ctx->textures_path.we_texture_path);
	return (1);
}

static void	make_background(t_ctx *ctx, unsigned int c1, unsigned int c2)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->win.height)
	{
		x = 0;
		while (x < ctx->win.width)
		{
			if (y < ctx->win.height / 2)
				put_pixel(ctx->textures[0], x, y, c1);
			else
				put_pixel(ctx->textures[0], x, y, c2);
			++x;
		}
		++y;
	}
}
