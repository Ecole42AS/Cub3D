/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:12:58 by astutz            #+#    #+#             */
/*   Updated: 2024/02/10 14:28:00 by astutz           ###   ########.fr       */
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

int	parser(char *file_path, t_parsing_data *data)
{
	int		fd;

	fd = open_file(file_path);
	if (fd == -1)
		return (1);
	if (parse_texture_paths(data->texture, fd) == 1)
	{
		close(fd);
		return (1);
	}
	data->map->parsed_map = map_parsing(fd, file_path);
	close(fd);
	if (data->map == NULL)
	{
		free_texture(data->texture);
		return (1);
	}
	if (!check_map_validity(data->map->parsed_map))
	{
		free_texture(data->texture);
		free_map(data->map->parsed_map);
		return (1);
	}
	return (0);
}