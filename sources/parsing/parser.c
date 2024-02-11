/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:12:58 by astutz            #+#    #+#             */
/*   Updated: 2024/02/11 17:13:40 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*ajouter void *img à la struct s_image et s_vec size*/
// int	set_texture(void *mlx, t_image *img, char *path, char *name)
// {
// 	if (path == NULL)
// 	{
// 		printf("Error, expected a path after '%s'\n", name);
// 		return (1);
// 	}
// 	if (path[ft_strlen(path) - 1] == '\n')
// 		path[ft_strlen(path) - 1] = '\0';
// 	img->img = mlx_xpm_file_to_image(mlx, path, &img->size.x,
// 			&img->size.y);
// 	if (img->img == NULL)
// 	{
// 		printf("Error, invalid path '%s'\n", path);
// 		return (1);
// 	}
// 	img->addr = mlx_get_data_addr(img->img, &img->bpp,
// 			&img->line_len, &img->endian);
// 	return (0);
// }

int	parser(char *file_path, t_ctx *ctx)
{
	int		fd;

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
	if (ctx->map == NULL)
		return (0);
	return (1);
}
