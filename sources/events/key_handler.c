/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:49:26 by lray              #+#    #+#             */
/*   Updated: 2023/12/30 00:56:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_handler(int keycode, void *param)
{
	t_ctx *ctx = param;

	if (keycode == KEY_ESC)
	{
		ctx_free(ctx);
		exit (0);
	}
	else if (keycode == KEY_W)
		printf("-> W !!!\n");
	else if (keycode == KEY_A)
		printf("-> A !!!\n");
	else if (keycode == KEY_S)
		printf("-> S !!!\n");
	else if (keycode == KEY_D)
		printf("-> D !!!\n");
	else if (keycode == KEY_UP)
	{
		printf("-> KEYUP !!!\n");
		ctx_show(ctx);
	}
	else if (keycode == KEY_DOWN)
	{
		printf("-> KEYDOWN !!!\n");
		ctx_show(ctx);
	}
	else if (keycode == KEY_LEFT)
		printf("-> KEYLEFT !!!\n");
	else if (keycode == KEY_RIGHT)
		printf("-> KEYRIGHT !!!\n");
	printf("keycode -> %d\n", keycode);
	return (0);
}
