/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:17:10 by astutz            #+#    #+#             */
/*   Updated: 2024/02/11 23:47:51 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	valide_celle(char cell, int *player_count);

char	**map_parsing(int fd, char *file_path)
{
	t_veci	*map_size;
	int		map_line_number;
	char	**map;
	char	*line;

	map_size = ft_malloc_failed_msg(1, sizeof(t_veci));
	map_line_number = get_map_line_number(file_path);
	line = gnl_unempty(fd);
	if (!line)
		return (NULL);
	map = ft_calloc(map_line_number * 2, sizeof(char *));
	if (!map)
		free(line);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[map_size->y] = line;
		if ((int)ft_strlen(line) > map_size->x)
			map_size->x = ft_strlen(line);
		line = get_next_line(fd);
		map_size->y++;
	}
	free(map_size);
	return (map);
}

int	get_map_line_number(char *file_path)
{
	int		fd;
	char	*line;
	int		line_number;

	fd = open_file(file_path);
	line_number = 0;
	while (1)
	{
		line = gnl_unempty(fd);
		if (line == NULL)
			break ;
		free(line);
		line_number++;
	}
	close(fd);
	line_number -= 6;
	return (line_number);
}

int	is_map_closed(char **map)
{
	t_veci	p;
	char	c;

	p.y = -1;
	while (map[++p.y] != NULL)
	{
		p.x = -1;
		while (map[p.y][++p.x] != '\0')
		{
			c = map[p.y][p.x];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (p.y == 0 || p.x == 0 || map[p.y][p.x + 1] == '\0' ||
					map[p.y + 1] == NULL || map[p.y][p.x + 1] == ' ' ||
					map[p.y + 1][p.x] == ' ' || map[p.y][p.x - 1] == ' ' ||
					map[p.y - 1][p.x] == ' ')
				{
					ft_putstr_fd("Error, map is not closed\n", 2);
					return (0);
				}
			}
		}
	}
	return (1);
}

int	check_map_validity(t_ctx *ctx)
{
	t_veci	pos;
	int		player_count;
	char	cell;

	player_count = 0;
	pos.y = -1;
	while (ctx->map->data[++pos.y] != NULL)
	{
		pos.x = -1;
		while (ctx->map->data[pos.y][++pos.x] != '\0')
		{
			cell = ctx->map->data[pos.y][pos.x];
			if (!valide_celle(cell, &player_count))
				return (0);
			if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
			{
				if (cell == 'N')
					player_init(&ctx->player, (t_vec){pos.x + 0.5, pos.y + 0.5}, (t_vec){0, -1}, (t_vec){-0.66, 0});
				else if (cell == 'S')
					player_init(&ctx->player, (t_vec){pos.x + 0.5, pos.y + 0.5}, (t_vec){0, 1}, (t_vec){0.66, 0});
				else if (cell == 'E')
					player_init(&ctx->player, (t_vec){pos.x + 0.5, pos.y + 0.5}, (t_vec){-1, 0}, (t_vec){0, 0.66});
				else if (cell == 'W')
					player_init(&ctx->player, (t_vec){pos.x + 0.5, pos.y + 0.5}, (t_vec){1, 0}, (t_vec){0, -0.66});

			}
		}
	}
	if (player_count != 1)
	{
		ft_putstr_fd("Error, exactly one player must be on the map\n", 2);
		return (0);
	}
	return (1);
}

static int	valide_celle(char cell, int *player_count)
{
	if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
	{
		(*player_count)++;
		return (1);
	}
	if (cell == '0' || cell == '1' || cell == ' ')
		return (1);
	ft_putstr_fd("Error, invalid character\n", 2);
	return (0);
}
