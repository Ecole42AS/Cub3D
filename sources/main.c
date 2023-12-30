/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:15:29 by astutz            #+#    #+#             */
/*   Updated: 2023/12/30 02:14:53 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIN_NAME	"Proto"
#define WIN_WIDTH	800
#define WIN_HEIGHT	640
#define IMG_HEIGTH	320
#define	IMG_WIDTH	320

#include "../includes/cub3d.h"

/*
	TODO:
		- win_show
		- Ajouter win_show() a ctx_show()
*/

int	main(void)
{
	t_ctx ctx;

	ctx_init(&ctx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	mlx_hook(ctx.win.win, ON_DESTROY, 0, close_handler, &ctx);
	mlx_key_hook(ctx.win.win, key_handler, &ctx);
	mlx_loop_hook(ctx.mlx, gameloop, &ctx);
	mlx_loop(ctx.mlx);
	ctx_free(&ctx);
	return (0);
}
