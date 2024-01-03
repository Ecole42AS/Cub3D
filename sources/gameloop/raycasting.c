/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:01:13 by lray              #+#    #+#             */
/*   Updated: 2024/01/04 00:23:25 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#include <math.h>

static void	draw_verline(t_image *frame, int col, int start, int end);

t_image	*raycasting(t_ctx *ctx, t_image *frame)
{
	int		x;

	x = 0;
	while (x < ctx->win.width)
	{
		/* Camera Space */
		double	cameraX = 2 * x / (double)ctx->win.width - 1;
		double	rayDirX = ctx->player.dir.x + ctx->player.cam.x * cameraX;
		double	rayDirY = ctx->player.dir.y + ctx->player.cam.y * cameraX;

		int		mapX = (int)ctx->player.pos.x;
		int		mapY = (int)ctx->player.pos.y;

		double	sideDistX;
		double	sideDistY;

		double	deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double	deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double	perpWallDist;

		int		stepX;
		int		stepY;

		int		hit = 0;

		int		side;

		/* Calculate step and inital*/
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (ctx->player.pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - ctx->player.pos.x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (ctx->player.pos.y - mapY) *deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - ctx->player.pos.y) * deltaDistY;
		}

		/* DDA ALGO */
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (ctx->map.map[mapX][mapY] > 0)
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		int lineHeigth = (int)(ctx->win.height / perpWallDist);

		int drawStart = -lineHeigth / 2 + ctx->win.height / 2;
		if (drawStart < 0)
			drawStart = 0;

		int drawEnd = lineHeigth / 2 + ctx->win.height / 2;
		if (drawEnd >= ctx->win.height)
			drawEnd = ctx->win.height - 1;

		draw_verline(frame, x, drawStart, drawEnd);

		++x;
	}
	return (frame);
}

static void	draw_verline(t_image *frame, int col, int start, int end)
{
	int	y;

	y = start;
	while (y < end)
	{
		put_pixel(frame, col, y, CLR_RED);
		++y;
	}
}
