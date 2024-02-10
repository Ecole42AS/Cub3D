
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

char	*tex_paths[] = {
	"assets/redbrick.xpm",		//NORD
	"assets/mossy.xpm",			//SUD
	"assets/greystone.xpm",		//EST
	"assets/colorstone.xpm",	//OUEST
};

int main(int ac, char **av)
{
	t_parsing_data data;
	t_ctx ctx;

	if (ac != 2)
	{
/* 		ft_putstr_fd("Invalid arguments\n", 2);
		return (1); */
		av[1] = "maps/test_map.cub";
	}
	if (parsing_data_init(&data))
	{
		return (1);
	}
	if (parser(av[1], &data))
		return(1);
	ctx_init(&ctx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (ctx_init_textures(&ctx, data.color, data.texture) != 0)
	{
		ft_putstr_fd("Error when initializing texture\n", 2);
		ctx_free(&ctx);
		return (1);
	}
	ctx.map.parsed_map = data.map->parsed_map;
	ctx.map.map_size = data.map->map_size;
	player_init(&ctx.player, (t_vec){10, 10}, (t_vec){-1, 0}, (t_vec){0, 0.66});
	mlx_hook(ctx.win.win, ON_DESTROY, 0, close_handler, &ctx);
	mlx_hook(ctx.win.win, 2, 1L<<0, key_handler, &ctx);
	mlx_loop_hook(ctx.mlx, gameloop, &ctx);
	mlx_do_key_autorepeaton(ctx.mlx);
	mlx_loop(ctx.mlx);
	ctx_free(&ctx);
	return (0);
}
