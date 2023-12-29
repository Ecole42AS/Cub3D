/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:49:26 by lray              #+#    #+#             */
/*   Updated: 2023/12/29 23:35:27 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_handler(int keycode, void *param)
{
	t_vars *vars = param;

	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
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
		printf("-> KEYUP !!!\n");
	else if (keycode == KEY_DOWN)
		printf("-> KEYDOWN !!!\n");
	else if (keycode == KEY_LEFT)
		printf("-> KEYLEFT !!!\n");
	else if (keycode == KEY_RIGHT)
		printf("-> KEYRIGHT !!!\n");
	printf("keycode -> %d\n", keycode);
	return (0);
}
