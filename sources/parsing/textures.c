/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:21:50 by astutz            #+#    #+#             */
/*   Updated: 2024/02/15 17:31:03 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_and_set_texture(t_texture *texture, int fd, t_ctx *ctx)
{
	char	*line;
	char	**split_result;

	line = gnl_unempty(fd);
	if (!line)
		return (0);
	printf("%s", line);
	split_result = ft_split(line, ' ');
	free(line);
	if (!ft_strcmp(split_result[0], "F") || !ft_strcmp(split_result[0], "C"))
		parse_colors(fd, &ctx->color);
	if (!compare_split_result(split_result))
		return (0);
	texture_path_setter(texture, split_result[1], split_result[0]);
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

int	parse_texture_paths(t_texture *texture, int fd, t_ctx *ctx)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!parse_and_set_texture(texture, fd, ctx))
			return (0);
	}
	return (1);
}

int	compare_split_result(char **split_result)
{
	if ((!split_result || split_result[2])
		&& ft_strcmp(split_result[0], "SO")
		&& ft_strcmp(split_result[0], "NO")
		&& ft_strcmp(split_result[0], "EA")
		&& ft_strcmp(split_result[0], "WE")
		&& ft_strcmp(split_result[0], "F")
		&& ft_strcmp(split_result[0], "C"))
	{
		free_split(split_result);
		ft_putstr_fd("A texture is missing in the map file\n", 2);
		return (0);
	}
	return (1);
}
