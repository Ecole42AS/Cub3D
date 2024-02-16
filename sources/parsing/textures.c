/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:21:50 by astutz            #+#    #+#             */
/*   Updated: 2024/02/16 18:14:39 by lray             ###   ########.fr       */
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
	split_result = ft_split(line, ' ');
	free(line);
	if (!compare_split_result(split_result))
		return (0);
	texture_path_setter(texture, split_result[1], split_result[0], &ctx->color);
	free_split(split_result);
	return (1);
}

void	texture_path_setter(t_texture *t, char *split, const char *prefix,
	t_color *color)
{
	if (!ft_strcmp(prefix, "NO"))
	{
		t->no_texture_path = ft_strdup(split);
		t->no_texture_path[ft_strlen(split) - 1] = '\0';
	}
	else if (!ft_strcmp(prefix, "SO"))
	{
		t->so_texture_path = ft_strdup(split);
		t->so_texture_path[ft_strlen(split) - 1] = '\0';
	}
	else if (!ft_strcmp(prefix, "WE"))
	{
		t->we_texture_path = ft_strdup(split);
		t->we_texture_path[ft_strlen(split) - 1] = '\0';
	}
	else if (!ft_strcmp(prefix, "EA"))
	{
		t->ea_texture_path = ft_strdup(split);
		t->ea_texture_path[ft_strlen(split) - 1] = '\0';
	}
	else if (ft_strcmp(prefix, "F") == 0)
		color->rgb_floor = parse_color_string(split);
	else if (ft_strcmp(prefix, "C") == 0)
		color->rgb_ceiling = parse_color_string(split);
}

int	parse_texture_paths(t_texture *texture, int fd, t_ctx *ctx)
{
	int	i;

	i = -1;
	while (++i < 6)
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
