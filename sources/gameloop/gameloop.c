/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:01:19 by lray              #+#    #+#             */
/*   Updated: 2024/01/02 18:29:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define TILE_SIZE 20

static void			render(t_ctx *ctx, t_image *img);


int gameloop(t_ctx *ctx)
{
	t_image *frame;

	frame = NULL;
	frame = img_create(ctx->mlx, ctx->win.width, ctx->win.height);
	frame = raycasting(ctx, frame);
	render(ctx, frame);
	return (1);
}

/*
	TODO:
		- The render() function must be move in it's own file.
*/
static void render(t_ctx *ctx, t_image *img)
{
	mlx_put_image_to_window(ctx->mlx, ctx->win.win, img->data, 0, 0);
	mlx_destroy_image(ctx->mlx, img->data);
	free(img);
}
