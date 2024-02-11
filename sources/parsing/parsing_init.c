/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:44:25 by astutz            #+#    #+#             */
/*   Updated: 2024/02/11 20:10:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_color *color_init()
{
	t_color *color = (t_color *)malloc(sizeof(t_color));
	if (color == NULL)
		return (NULL);
	color->rgb_floor = 0;
	color->rgb_ceiling = 0;
	return (color);
}

static t_texture *texture_init()
{
	t_texture *texture = (t_texture *)malloc(sizeof(t_texture));

	if (texture == NULL)
	{
		ft_putstr_fd("Malloc failed\n", 2);
		return (NULL);
	}
	texture->no_texture_path = NULL;
	texture->so_texture_path = NULL;
	texture->we_texture_path = NULL;
	texture->ea_texture_path = NULL;
	return (texture);
}

static t_map *map_init()
{
	t_map *map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);

	map->map_size.x = 0;
	map->map_size.y = 0;
	map->data = NULL;

	return (map);
}

int parsing_data_init(t_parsing_data *data)
{
	data->color = color_init();
	if (data->color == NULL)
		return (1);
	data->texture = texture_init();
	if (data->texture == NULL)
	{
		free(data->color);
		return (1);
	}
	data->map = map_init();
	if (data->map == NULL)
	{
		free(data->color);
		free(data->texture);
		return (1);
	}
	return (0);
}
