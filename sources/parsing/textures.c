/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:21:50 by astutz            #+#    #+#             */
/*   Updated: 2024/02/12 10:50:19 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int parse_and_set_texture(t_texture *texture, int fd)
{
    char *line = gnl_unempty(fd);
    if (!line)
        return 1;
    char **split_result = ft_split(line, ' ');
    free(line);
    if ((!split_result 
    || split_result[2])
    && ft_strcmp(split_result[0], "SO") 
    && ft_strcmp(split_result[0], "NO") 
    && ft_strcmp(split_result[0], "EA") 
    && ft_strcmp(split_result[0], "WE"))
    {
        free_split(split_result);
        return 1;
    }

    texture_path_setter(texture, split_result[1], split_result[0]);

    free_split(split_result);
    return 0;
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
    int i;

    i = -1;
    while (++i < 4)
    {
        if (parse_and_set_texture(texture, fd) != 0)
            return (1);
    }
    return (0);
}
