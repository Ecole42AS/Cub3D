/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:01:13 by lray              #+#    #+#             */
/*   Updated: 2024/01/08 07:37:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	draw_verline(t_image *frame, int col, int start, int end, int color);

t_image	*raycasting(t_ctx *ctx, t_image *frame)
{
	int		x;
	t_ray	ray;
	int		line_heigth;
	int		draw_start;
	int		draw_end;

	x = 0;
	line_heigth = 0;
	while (x < ctx->win.width)
	{
		ray_init(ctx, &ray, x);
		ray_dda(ctx, &ray);
		ray_calculate_perp_wall_dist(&ray);
		line_heigth = (int)(ctx->win.height / ray.perp_wall_dist);
		draw_start = -line_heigth / 2 + ctx->win.height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_heigth / 2 + ctx->win.height / 2;
		if (draw_end >= ctx->win.height)
			draw_end = ctx->win.height - 1;
		if (ray.hit == RAY_EA)
		{
			if (draw_verline(frame, x, draw_start, draw_end, CLR_RED) != 0)
				return (NULL);
		}
		else if (ray.hit == RAY_WE)
		{
			if (draw_verline(frame, x, draw_start, draw_end, CLR_INDIGO) != 0)
				return (NULL);
		}
		else if (ray.hit == RAY_NO)
		{
			if (draw_verline(frame, x, draw_start, draw_end, CLR_ORANGE) != 0)
				return (NULL);
		}
		else
		{
			if (draw_verline(frame, x, draw_start, draw_end, CLR_MAGENTA) != 0)
				return (NULL);
		}
		++x;
	}
	return (frame);
}

static int	draw_verline(t_image *frame, int col, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
	{
		if (put_pixel(frame, col, y, color) != 0)
		{
			ft_putstr_fd("Error when drawing a line", 2);
			return (1);
		}
		++y;
	}
	return (0);
}
