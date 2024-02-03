/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:10:40 by lray              #+#    #+#             */
/*   Updated: 2024/02/03 13:41:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ctx_free(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		img_free(ctx, ctx->textures[i]);
		++i;
	}
	win_free(&ctx->win);
	//mlx_destroy_display(ctx->mlx);
	free(ctx->mlx);
	ctx->mlx = NULL;
	ctx = NULL;
	exit (0);
}
