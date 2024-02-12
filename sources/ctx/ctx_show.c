/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:52:31 by lray              #+#    #+#             */
/*   Updated: 2024/01/09 23:14:49 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ctx_show(t_ctx *ctx)
{
	printf("ctx : %p\n", ctx);
	printf("ctx->mlx : %p\n", ctx->mlx);
}