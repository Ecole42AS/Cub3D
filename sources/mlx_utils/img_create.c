/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:23:00 by lray              #+#    #+#             */
/*   Updated: 2023/11/19 16:23:44 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


t_image *img_create(void *mlx, int width, int height)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
	{
		printf("Malloc failed\n");
		return (NULL);
	}
	img->data = mlx_new_image(mlx, width, height);
	if (!img->data)
	{
		printf("Loading image failed\n");
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->data, &img->bpp, &img->line_len, &img->endian);
	if (!img->addr)
	{
		printf("Cannont get images informations\n");
		return (NULL);
	}
	img->width = width;
	img->height = height;
	return (img);
}
