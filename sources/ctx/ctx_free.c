/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:10:40 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 20:16:45 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ctx_free(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (ctx->map)
	{
		ctx->map->map_size.x = 0;
		ctx->map->map_size.y = 0;
		free_map(ctx->map->data);
		free(ctx->map);
		ctx->map = NULL;
	}
	free_texture(&ctx->textures_path);
	while (i < 5)
	{
		img_free(ctx, ctx->textures[i]);
		ctx->textures[i] = NULL;
		++i;
	}
	win_free(&ctx->win);
	if (ctx->mlx)
	{
		free(ctx->mlx);
		ctx->mlx = NULL;
	}
}
