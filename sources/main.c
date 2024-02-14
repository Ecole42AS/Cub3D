
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

static int	parse_and_validate(t_ctx *ctx, char *path);
static int	game_init(t_ctx *ctx);
static void	game_run(t_ctx *ctx);
static void	show_usage(void);

int	main(int ac, char **av)
{
	t_ctx	ctx;

	if (ac != 2)
	{
		show_usage();
		return (1);
	}
	if (!ctx_init(&ctx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME))
	{
		ctx_free(&ctx);
		return (1);
	}
	if (!parse_and_validate(&ctx, av[1]))
	{
		ctx_free(&ctx);
		return (1);
	}
	if (!game_init(&ctx))
	{
		ctx_free(&ctx);
		return (1);
	}
	game_run(&ctx);
	ctx_free(&ctx);
	return (0);
}

static int	parse_and_validate(t_ctx *ctx, char *path)
{
	if (!parser(path, ctx))
		return (0);
	if (!ctx_validation(ctx))
		return (0);
	return (1);
}

static int	game_init(t_ctx *ctx)
{
	ctx->mlx = mlx_init();
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
	mlx_hook(ctx->win.win, 2, 1L << 0, keypress_handler, ctx);
	mlx_hook(ctx->win.win, 3, 1L << 1, keyrelease_handler, ctx);
	mlx_loop_hook(ctx->mlx, gameloop, ctx);
	mlx_loop(ctx->mlx);
}

static void	show_usage(void)
{
	printf("Usage: ./cub3d [file_path]\n");
	printf("file_path: Path to the map file to be used by the game.\n");
}
