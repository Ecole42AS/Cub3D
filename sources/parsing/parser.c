/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:12:58 by astutz            #+#    #+#             */
/*   Updated: 2024/02/16 13:35:38 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parser(char *file_path, t_ctx *ctx)
{
	int	fd;

	fd = open_file(file_path);
	if (fd == -1)
		return (0);
	if (!parse_texture_paths(&ctx->textures_path, fd, ctx))
	{
		close(fd);
		return (0);
	}
	ctx->map->data = map_parsing(fd, file_path);
	close(fd);
	if (ctx->map->data == NULL)
		return (0);
	return (1);
}
