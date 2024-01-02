/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:01:13 by lray              #+#    #+#             */
/*   Updated: 2024/01/02 18:30:02 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#include <math.h>

static void	draw_verline(t_image *frame, int col, int start, int end);

t_image	*raycasting(t_ctx *ctx, t_image *frame)
{
	double	posX = 22;
	double	posY = 12;
	double	dirX = -1;
	double	dirY = 0;
	double	planeX = 0;
	double	planeY = 0.66;
	int		x = 0;

	while (x < ctx->win.width)
	{
		double	cameraX = 2 * x / (double)ctx->win.width - 1;
		double	rayDirX = dirX + planeX * cameraX;
		double	rayDirY = dirY + planeY * cameraX;
		int		mapX = (int)posX;
		int		mapY = (int)posY;
		double	sideDistX;
		double	sideDistY;
		double	deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double	deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double	perpWallDist;
		int		stepX;
		int		stepY;
		int		hit = 0;
		int		side;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) *deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
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
		put_pixel(frame, col, y, CLR_GREEN);
		++y;
	}
}
