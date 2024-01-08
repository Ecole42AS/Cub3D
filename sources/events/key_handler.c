/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:49:26 by lray              #+#    #+#             */
/*   Updated: 2024/01/08 04:12:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double move_speed = 0.9;
double rot_speed = 0.3;

int	key_handler(int keycode, void *param)
{
	t_ctx *ctx = param;
	double	new_x;
	double	new_y;
	double old_dir_x;
	double old_plane_x;

	if (keycode == KEY_ESC)
	{
		ctx_free(ctx);
		exit (0);
	}
	else if (keycode == KEY_W)
	{
		new_x = ctx->player.pos.x + ctx->player.dir.x * move_speed;
		new_y = ctx->player.pos.y + ctx->player.dir.y * move_speed;
		ctx->player.pos.x = new_x;
		ctx->player.pos.y = new_y;
	}
	else if (keycode == KEY_S)
	{
		new_x = ctx->player.pos.x - ctx->player.dir.x * move_speed;
		new_y = ctx->player.pos.y - ctx->player.dir.y * move_speed;
		ctx->player.pos.x = new_x;
		ctx->player.pos.y = new_y;
	}
	else if (keycode == KEY_A)
	{
		new_x = ctx->player.pos.x - ctx->player.dir.y * move_speed;
		new_y = ctx->player.pos.y + ctx->player.dir.x * move_speed;
		ctx->player.pos.x = new_x;
		ctx->player.pos.y = new_y;
	}
	else if (keycode == KEY_D)
	{
		new_x = ctx->player.pos.x + ctx->player.dir.y * move_speed;
		new_y = ctx->player.pos.y - ctx->player.dir.x * move_speed;
		ctx->player.pos.x = new_x;
		ctx->player.pos.y = new_y;
	}
	else if (keycode == KEY_UP)
	{
		new_x = ctx->player.pos.x + ctx->player.dir.x * move_speed;
		new_y = ctx->player.pos.y + ctx->player.dir.y * move_speed;
		ctx->player.pos.x = new_x;
		ctx->player.pos.y = new_y;
	}
	else if (keycode == KEY_DOWN)
	{
		new_x = ctx->player.pos.x - ctx->player.dir.x * move_speed;
		new_y = ctx->player.pos.y - ctx->player.dir.y * move_speed;
		ctx->player.pos.x = new_x;
		ctx->player.pos.y = new_y;
	}
	else if (keycode == KEY_LEFT)
	{
		old_dir_x = ctx->player.dir.x;
		old_plane_x = ctx->player.cam.x;
		ctx->player.dir.x = ctx->player.dir.x * cos(rot_speed) - ctx->player.dir.y * sin(rot_speed);
		ctx->player.dir.y = old_dir_x * sin(rot_speed) + ctx->player.dir.y  * cos(rot_speed);
		ctx->player.cam.x = ctx->player.cam.x * cos(rot_speed) - ctx->player.cam.y * sin(rot_speed);
		ctx->player.cam.y = old_plane_x * sin(rot_speed) + ctx->player.cam.y * cos(rot_speed);
	}
	else if (keycode == KEY_RIGHT)
	{
		old_dir_x = ctx->player.dir.x;
		old_plane_x = ctx->player.cam.x;
		ctx->player.dir.x = ctx->player.dir.x * cos(-rot_speed) - ctx->player.dir.y * sin(-rot_speed);
		ctx->player.dir.y = old_dir_x * sin(-rot_speed) + ctx->player.dir.y  * cos(-rot_speed);
		ctx->player.cam.x = ctx->player.cam.x * cos(-rot_speed) - ctx->player.cam.y * sin(-rot_speed);
		ctx->player.cam.y = old_plane_x * sin(-rot_speed) + ctx->player.cam.y * cos(-rot_speed);
	}
	return (0);
}

