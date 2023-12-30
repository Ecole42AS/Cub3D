/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:51:50 by lray              #+#    #+#             */
/*   Updated: 2023/12/30 00:55:14 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ctx_init(t_ctx *ctx, int width, int height, char *name)
{
	ctx->mlx = mlx_init();
	ctx->win = mlx_new_window(ctx->mlx, width, height, name);
}
