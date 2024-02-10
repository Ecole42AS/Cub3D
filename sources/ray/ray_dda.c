/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:14:43 by lray              #+#    #+#             */
/*   Updated: 2024/02/10 16:51:14 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void check_hit(t_ctx *ctx, t_ray *ray);

void ray_dda(t_ctx *ctx, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		check_hit(ctx, ray);
	}
}

static void check_hit(t_ctx *ctx, t_ray *ray)
{
	if (ctx->map.parsed_map[ray->map.y][ray->map.x] == '1')
	{
		if (ray->side == 0)
		{
			if (ray->dir.x > 0)
				ray->hit = RAY_SU;
			else
				ray->hit = RAY_NO;
		}
		else
		{
			if (ray->dir.y > 0)
				ray->hit = RAY_EA;
			else
				ray->hit = RAY_WE;
		}
	}
}
