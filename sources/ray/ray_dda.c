/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:14:43 by lray              #+#    #+#             */
/*   Updated: 2024/01/07 05:44:51 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_dda(t_ctx *ctx, t_ray *ray)
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
		if (ctx->map.map[ray->map.x][ray->map.y] > 0)
		{
			if (ray->side == 0)
			{
				if (ray->dir.x > 0)
					ray->hit = RAY_WE;
				else
					ray->hit = RAY_EA;
			}
			else
			{
				if (ray->dir.y > 0)
					ray->hit = RAY_SU;
				else
					ray->hit = RAY_NO;
			}
		}
	}
}
