/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:15:29 by astutz            #+#    #+#             */
/*   Updated: 2023/12/31 16:25:20 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIN_NAME	"Proto"
#define WIN_WIDTH	800
#define WIN_HEIGHT	640
#define IMG_HEIGTH	320
#define	IMG_WIDTH	320

#include "../includes/cub3d.h"

int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);

	mlx_key_hook(vars.win, key_handler, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_handler, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
