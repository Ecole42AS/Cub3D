/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:38:45 by lray              #+#    #+#             */
/*   Updated: 2024/01/04 01:25:16 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "structures.h"
# include <math.h>

void	ray_init(t_ctx *ctx, t_ray *ray, int x);
void	ray_dda(t_ctx *ctx, t_ray *ray);
void	ray_calculate_perp_wall_dist(t_ray *ray);

#endif
