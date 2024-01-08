/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:01:19 by lray              #+#    #+#             */
/*   Updated: 2024/01/08 07:44:36 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void			render(t_ctx *ctx, t_image *img);

int gameloop(t_ctx *ctx)
{
	t_image *frame;

	frame = NULL;
	frame = img_create(ctx->mlx, ctx->win.width, ctx->win.height);
	if (!frame)
	{
		ft_putstr_fd("Error when creating new frame\n", 2);
		ctx_free(ctx);
		exit(EXIT_FAILURE);
	}
	if (put_img_to_img(frame, ctx->textures[0], 0, 0) != 0)
	{
		ft_putstr_fd("Error when adding pixels to frame\n", 2);
		ctx_free(ctx);
		exit(EXIT_FAILURE);
	}
	frame = raycasting(ctx, frame);
	if (!frame)
	{
		ft_putstr_fd("Error will raycasting\n", 2);
		ctx_free(ctx);
		exit(EXIT_FAILURE);
	}
	put_img_to_img(frame, ctx->textures[1], 0, 0);
	put_img_to_img(frame, ctx->textures[2], 64, 0);
	put_img_to_img(frame, ctx->textures[3], 128, 0);
	put_img_to_img(frame, ctx->textures[4], 128 + 64, 0);
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
