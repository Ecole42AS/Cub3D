/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:34:14 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 21:55:05 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	win_init(t_ctx *ctx)
{
	ctx->win.mlx = ctx->mlx;
	ctx->win.win = mlx_new_window(ctx->mlx, ctx->win.width, \
		ctx->win.height, ctx->win.name);
}
