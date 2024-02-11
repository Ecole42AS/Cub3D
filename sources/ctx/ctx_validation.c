/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:51:07 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 23:02:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_color_validity(t_color colors);
static int	check_textures_paths_validity(t_texture textures);
static int	check_texture_path_validity(char *texture_path, char *texture_name);

int	ctx_validation(t_ctx *ctx)
{
	if (!check_map_validity(ctx->map->data))
		return (0);
	if (!is_map_closed(ctx->map->data))
		return (0);
	if (!check_color_validity(ctx->color))
		return (0);
	if (!check_textures_paths_validity(ctx->textures_path))
		return (0);
	return (1);
}

static int	check_color_validity(t_color colors)
{
	if (colors.rgb_ceiling == 0 || colors.rgb_floor == 0)
	{
		ft_putstr_fd("Floor or ceiling color is missing in the map file\n", 2);
		return (0);
	}
	return (1);
}

static int	check_textures_paths_validity(t_texture textures)
{
	if (!check_texture_path_validity(textures.no_texture_path, "north"))
		return (0);
	if (!check_texture_path_validity(textures.so_texture_path, "south"))
		return (0);
	if (!check_texture_path_validity(textures.we_texture_path, "west"))
		return (0);
	if (!check_texture_path_validity(textures.ea_texture_path, "east"))
		return (0);
	return (1);
}

static int	check_texture_path_validity(char *texture_path, char *texture_name)
{
	int	fd;

	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("The ", 2);
		ft_putstr_fd(texture_name, 2);
		ft_putstr_fd(" texture file is inaccessible or does not exist\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}
