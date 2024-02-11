/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:21:50 by astutz            #+#    #+#             */
/*   Updated: 2024/02/11 20:08:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int parse_and_set_texture(t_texture *texture, int fd, const char *prefix)
{
	char *line = gnl_unempty(fd);
	if (!line)
		return 0;

	char **split_result = ft_split(line, ' ');
	free(line);

	if (!split_result || ft_strcmp(split_result[0], prefix) || split_result[2])
	{
		free_split(split_result);
		ft_putstr_fd("A texture is missing in the map file\n", 2);
		return 0;
	}

	texture_path_setter(texture, split_result[1], prefix);

	free_split(split_result);
	return 1;
}

void texture_path_setter(t_texture *texture, const char *path, const char *prefix)
{
	if (!strcmp(prefix, "NO"))
	{
		texture->no_texture_path = ft_strdup(path);
		texture->no_texture_path[ft_strlen(path) - 1] = '\0';
	}
	else if (!strcmp(prefix, "SO"))
	{
		texture->so_texture_path = ft_strdup(path);
		texture->so_texture_path[ft_strlen(path) - 1] = '\0';
	}
	else if (!strcmp(prefix, "WE"))
	{
		texture->we_texture_path = ft_strdup(path);
		texture->we_texture_path[ft_strlen(path) - 1] = '\0';
	}
	else if (!strcmp(prefix, "EA"))
	{
		texture->ea_texture_path = ft_strdup(path);
		texture->ea_texture_path[ft_strlen(path) - 1] = '\0';
	}
}

int parse_texture_paths(t_texture *texture, int fd)
{
	const char *prefixes[] = {"NO", "SO", "WE", "EA"};
	char *line;
	line = NULL;

	for (int i = 0; i < (int)(sizeof(prefixes) / sizeof(prefixes[0])); ++i)
	{
		if (!parse_and_set_texture(texture, fd, prefixes[i]) != 0)
		{
			line = get_next_line(fd);
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			return 0;
		}
	}
	return 1;
}
