/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:01:19 by lray              #+#    #+#             */
/*   Updated: 2023/12/30 04:37:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define TILE_SIZE 20

static t_image		*make_frame(t_ctx *ctx, t_image *img);
static unsigned int	choose_random_color(void);
static t_image		*make_checkboard(t_ctx *ctx, t_image *img, unsigned int color1, unsigned int color2);
static void			render(t_ctx *ctx, t_image *img);


int gameloop(t_ctx *ctx)
{
	t_image *img;

	img = NULL;
	img = make_frame(ctx, img);

	/*
		Logique de la composition de la fram
			1) ajouter le background (2 couleur, sol et ciel)
			2) process raytracing
			3) affichger le personnage
			4) ajouter l'interface et la minimap.
	*/

	render(ctx, img);
	return (1);
}

/*
	TODO:
		- MUST BE DELETED BEFORE PROD. ONLY FOR DEBUG
*/
static t_image *make_frame(t_ctx *ctx, t_image *img)
{
	unsigned int color1;
	unsigned int color2;

	img = img_create(ctx->mlx, ctx->win.width, ctx->win.height);
	color1 = choose_random_color();
	color2 = choose_random_color();
	img = make_checkboard(ctx, img, color1, color2);
	return (img);
}

/*
	TODO:
		- MUST BE DELETED BEFORE PROD. ONLY FOR DEBUG
*/
static unsigned int choose_random_color(void)
{
	unsigned int colors[] = {
		CLR_BLACK, CLR_GRAY, CLR_LIGHT_GRAY, CLR_DARK_GRAY, CLR_WHITE,
		CLR_RED, CLR_ORANGE, CLR_YELLOW, CLR_GREEN, CLR_BLUE, CLR_INDIGO,
		CLR_VIOLET, CLR_CYAN, CLR_MAGENTA, CLR_PURPLE, CLR_BROWN};
	size_t num_colors = sizeof(colors) / sizeof(colors[0]);

	unsigned int random_color = colors[rand() % num_colors];

	return random_color;
}

/*
	TODO:
		- MUST BE DELETED BEFORE PROD. ONLY FOR DEBUG
*/
static t_image	*make_checkboard(t_ctx *ctx, t_image *img, unsigned int color1, unsigned int color2)
{
	int x;
	int y;

	img = img_create(ctx->mlx, ctx->win.width, ctx->win.height);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if ((x / TILE_SIZE + y / TILE_SIZE) % 2 == 0)
				put_pixel(img, x, y, color1);
			else
				put_pixel(img, x, y, color2);
			++x;
		}
		++y;
	}
	return (img);
}

/*
	TODO:
		- The render() function must be move in it's own file.
*/
static void render(t_ctx *ctx, t_image *img)
{
	mlx_put_image_to_window(ctx->mlx, ctx->win.win, img->data, 0, 0);
	mlx_destroy_image(ctx->mlx, img->data);
	free(img);
}
