/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:01:19 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 20:26:49 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	render(t_ctx *ctx, t_image *img);

int	gameloop(t_ctx *ctx)
{
	t_image	*frame;

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
		ft_putstr_fd("Error while raycasting\n", 2);
		ctx_free(ctx);
		exit(EXIT_FAILURE);
	}
	render(ctx, frame);
	return (1);
}

static void	render(t_ctx *ctx, t_image *img)
{
	mlx_put_image_to_window(ctx->mlx, ctx->win.win, img->data, 0, 0);
	img_free(ctx, img);
}
