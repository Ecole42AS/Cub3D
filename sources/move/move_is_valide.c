/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_is_valide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:17:40 by lray              #+#    #+#             */
/*   Updated: 2024/02/10 14:24:47 by astutz           ###   ########.fr       */
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

	rounded_x = floor(new_x);
	rounded_y = floor(new_y);
	if (is_valide_new_x(ctx, rounded_x) && is_valide_new_y(ctx, rounded_y))
	{
		if (!is_wall(ctx, rounded_x, rounded_y))
			return (1);
	}
	return (0);
}

static int	is_valide_new_x(t_ctx *ctx, double new_x)
{
	if (new_x > 0 && new_x < ctx->map.map_size.x - 1)
		return (1);
	return (0);
}

static int	is_valide_new_y(t_ctx *ctx, double new_y)
{
	if (new_y > 0 && new_y < ctx->map.map_size.y - 1)
		return (1);
	return (0);
}

static int	is_wall(t_ctx *ctx, double new_x, double new_y)
{
	if (ctx->map.parsed_map[(int)new_x][(int)new_y] == 1)
		return (1);
	return (0);
}
