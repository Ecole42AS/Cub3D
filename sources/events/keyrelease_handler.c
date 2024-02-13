/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:09:44 by lray              #+#    #+#             */
/*   Updated: 2024/02/13 13:10:25 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	keyrelease_handler(int keycode, void *param)
{
	t_ctx	*ctx;

	ctx = param;
	if (keycode == KEY_W || keycode == KEY_UP)
		ctx->keys.w = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ctx->keys.s = 0;
	else if (keycode == KEY_A)
		ctx->keys.a = 0;
	else if (keycode == KEY_D)
		ctx->keys.d = 0;
	else if (keycode == KEY_LEFT)
		ctx->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		ctx->keys.right = 0;
	return (0);
}
