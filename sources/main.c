
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:15:29 by astutz            #+#    #+#             */
/*   Updated: 2024/01/14 16:28:06 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define WIN_NAME "Proto"
#define WIN_WIDTH 1920/1.5
#define WIN_HEIGHT 1080/1.5

static int	game_init(t_ctx *ctx);
static void	game_run(t_ctx *ctx);

int main(int ac, char **av)
{
	t_ctx ctx;

	if (ac != 2)
		av[1] = "maps/test_map.cub";
	if (!ctx_init(&ctx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME))
	{
		ft_putstr_fd("Error during data initialization\n", 2);
		ctx_free(&ctx);
		return (2);
	}
	if (!parser(av[1], &ctx))
	{
		ft_putstr_fd("Error during map parsing\n", 2);
		ctx_free(&ctx);
		return (3);
	}
	if (!ctx_validation(&ctx))
	{
		ft_putstr_fd("Error during validation\n", 2);
		ctx_free(&ctx);
		return (3);
	}
	if (!game_init(&ctx))
	{
		ft_putstr_fd("Error during game initialization\n", 2);
		ctx_free(&ctx);
		return (4);
	}
	game_run(&ctx);
	ctx_free(&ctx);
	return (0);
}

static int	game_init(t_ctx *ctx)
{

	ctx->mlx = mlx_init();
	player_init(&ctx->player, (t_vec){10, 10}, (t_vec){-1, 0}, (t_vec){0, 0.66});
	if (!ctx->mlx)
	{
		ft_putstr_fd("Error during mlx initialization\n", 2);
		return (0);
	}
	ctx_init_textures(ctx);
	win_init(ctx);
	return (1);
}

static void	game_run(t_ctx *ctx)
{
	mlx_hook(ctx->win.win, ON_DESTROY, 0, close_handler, ctx);
	mlx_hook(ctx->win.win, 2, 1L<<0, key_handler, ctx);
	mlx_loop_hook(ctx->mlx, gameloop, ctx);
	mlx_do_key_autorepeaton(ctx->mlx);
	mlx_loop(ctx->mlx);
}
