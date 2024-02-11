/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:51:07 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 17:39:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_color_validity(t_color colors);
static int	check_textures_paths_validity(t_texture textures);

int	ctx_validation(t_ctx *ctx)
{
	if (!check_map_validity(ctx->map->data))
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
	int	fd;

	fd = open(textures.no_texture_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("The north texture file is inaccessible or does not exist\n", 2);
		return (0);
	}
	close(fd);
	fd = open(textures.so_texture_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("The south texture file is inaccessible or does not exist\n", 2);
		return (0);
	}
		close(fd);
	fd = open(textures.we_texture_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("The west texture file is inaccessible or does not exist\n", 2);
		return (0);
	}
		close(fd);
	fd = open(textures.ea_texture_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("The east texture file is inaccessible or does not exist\n", 2);
		return (0);
	}
	return (1);
}
