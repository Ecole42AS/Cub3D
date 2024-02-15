/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:21:50 by astutz            #+#    #+#             */
/*   Updated: 2024/02/15 14:04:14 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_and_set_texture(t_texture *texture, int fd, const char *prefix) //t_ctx *ctx
{
	char	*line;
	char	**split_result;

	line = gnl_unempty(fd);
	if (!line)
		return (0);
	split_result = ft_split(line, ' ');
	free(line);
	// if (!ft_strcmp(split_result[0], "F") || !ft_strcmp(split_result[0], "C"))
		// parse_colors(fd, &ctx->color);
	if (!split_result || ft_strcmp(split_result[0], prefix) || split_result[2])
	{
		free_split(split_result);
		ft_putstr_fd("A texture is missing in the map file\n", 2);
		return (0);
	}
	texture_path_setter(texture, split_result[1], prefix);
	free_split(split_result);
	return (1);
}

void	texture_path_setter(t_texture *t, const char *path, const char *prefix)
{
	if (!strcmp(prefix, "NO"))
	{
		t->no_texture_path = ft_strdup(path);
		t->no_texture_path[ft_strlen(path) - 1] = '\0';
	}
	else if (!strcmp(prefix, "SO"))
	{
		t->so_texture_path = ft_strdup(path);
		t->so_texture_path[ft_strlen(path) - 1] = '\0';
	}
	else if (!strcmp(prefix, "WE"))
	{
		t->we_texture_path = ft_strdup(path);
		t->we_texture_path[ft_strlen(path) - 1] = '\0';
	}
	else if (!strcmp(prefix, "EA"))
	{
		t->ea_texture_path = ft_strdup(path);
		t->ea_texture_path[ft_strlen(path) - 1] = '\0';
	}
}

int	parse_texture_paths(t_texture *texture, int fd)
{
	char	*prefixes[4];
	char	*line;
	int		i;

	prefixes[0] = "NO";
	prefixes[1] = "SO";
	prefixes[2] = "WE";
	prefixes[3] = "EA";
	line = NULL;
	i = 0;
	while (i < (int)(sizeof(prefixes) / sizeof(prefixes[0])))
	{
		if (!parse_and_set_texture(texture, fd, prefixes[i]))
		{
			line = get_next_line(fd);
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (0);
		}
		++i;
	}
	return (1);
}
