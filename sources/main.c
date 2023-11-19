/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:15:29 by astutz            #+#    #+#             */
/*   Updated: 2023/11/19 17:07:39 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIN_NAME	"TEST"
#define WIN_WIDTH	800
#define WIN_HEIGHT	640
#define IMG_HEIGTH	320
#define	IMG_WIDTH	320

#include "../includes/cub3d.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	t_image	*img;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	img = img_create(mlx, WIN_WIDTH, WIN_HEIGHT);
	y = 0;
	x = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			put_pixel(img, x, y, 0x00FF00);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(mlx, win, img->data, 0, 0);
	mlx_loop(mlx);
	return (0);
}
