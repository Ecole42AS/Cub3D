/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:11:57 by lray              #+#    #+#             */
/*   Updated: 2024/02/13 13:18:13 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	keys_handler(t_ctx *ctx)
{
	if (ctx->keys.w == 1)
		go_front(ctx);
	if (ctx->keys.a == 1)
		go_left(ctx);
	if (ctx->keys.s == 1)
		go_back(ctx);
	if (ctx->keys.d == 1)
		go_right(ctx);
	if (ctx->keys.left)
		rotate_left(ctx);
	if (ctx->keys.right)
		rotate_right(ctx);
}
