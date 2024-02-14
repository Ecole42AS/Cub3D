/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:49:26 by lray              #+#    #+#             */
/*   Updated: 2024/02/13 13:09:15 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	keypress_handler(int keycode, void *param)
{
	t_ctx	*ctx;

	ctx = param;
	if (keycode == KEY_ESC)
	{
		ctx_free(ctx);
		exit (0);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		ctx->keys.w = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ctx->keys.s = 1;
	else if (keycode == KEY_A)
		ctx->keys.a = 1;
	else if (keycode == KEY_D)
		ctx->keys.d = 1;
	else if (keycode == KEY_LEFT)
		ctx->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		ctx->keys.right = 1;
	return (0);
}
