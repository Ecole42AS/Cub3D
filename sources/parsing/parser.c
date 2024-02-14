/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:12:58 by astutz            #+#    #+#             */
/*   Updated: 2024/02/14 15:37:44 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parser(char *file_path, t_ctx *ctx)
{
	int	fd;

	fd = open_file(file_path);
	if (fd == -1)
		return (0);
	if (!parse_texture_paths(&ctx->textures_path, fd))
	{
		close(fd);
		return (0);
	}
	parse_colors(fd, &ctx->color);
	ctx->map->data = map_parsing(fd, file_path);
	close(fd);
	if (ctx->map->data == NULL)
		return (0);
	return (1);
}
