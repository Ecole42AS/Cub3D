/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_is_valide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:17:40 by lray              #+#    #+#             */
/*   Updated: 2024/02/12 14:45:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_valide_new_x(t_ctx *ctx, double new_x);
static int	is_valide_new_y(t_ctx *ctx, double new_y);
static int	is_wall(t_ctx *ctx, double new_x, double new_y);

int	move_is_valide(t_ctx *ctx, double new_x, double new_y)
{
	double	rounded_x;
	double	rounded_y;

	if (new_x > ctx->player.pos.x)
		rounded_x = floor(new_x + 0.3);
	else
		rounded_x = floor(new_x - 0.3);
	if (new_y > ctx->player.pos.y)
		rounded_y = floor(new_y + 0.3);
	else
		rounded_y = floor(new_y - 0.3);
	if (is_valide_new_x(ctx, rounded_x) && is_valide_new_y(ctx, rounded_y))
	{
		if (!is_wall(ctx, rounded_x, rounded_y))
			return (1);
	}
	return (0);
}

static int	is_valide_new_x(t_ctx *ctx, double new_x)
{
	if (new_x > 0 && new_x < ctx->map->map_size.x - 1)
		return (1);
	return (0);
}

static int	is_valide_new_y(t_ctx *ctx, double new_y)
{
	if (new_y > 0 && new_y < ctx->map->map_size.y - 1)
		return (1);
	return (0);
}

static int	is_wall(t_ctx *ctx, double new_x, double new_y)
{
	if (ctx->map->data[(int)(new_y)][(int)(new_x)] == '1')
		return (1);
	return (0);
}
