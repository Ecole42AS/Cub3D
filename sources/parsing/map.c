/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:17:10 by astutz            #+#    #+#             */
/*   Updated: 2024/02/03 14:14:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*Voir pour mettre 	t_veci	*map_size; dans les param de la fonction(pour la norme)*/
char **map_parsing(int fd, char	*file_path)
{
	t_veci		*map_size;
	int			map_line_number;
	char 		**map;
	char		*line;

	map_size = ft_malloc_failed_msg(1, sizeof(t_veci));
	map_line_number = get_map_line_number(file_path);
	line = gnl_unempty(fd);
	if (!line)
		return (NULL);
	map = ft_calloc(map_line_number + 1, sizeof(char *));
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
	char	cell;

	p.y = -1;
	while (map[++p.y] != NULL)
	{
		p.x = -1;
		while (map[p.y][++p.x] != '\0')
		{
			cell = map[p.y][p.x];
			if (cell == '0' || cell == 'N' || cell == 'S' || cell == 'E'
				|| cell == 'W')
			{
				if (p.y == 0 || p.x == 0 || map[p.y][p.x + 1] == '\0' ||
					map[p.y + 1] == NULL || map[p.y][p.x + 1] == ' ' ||
					map[p.y + 1][p.x] == ' ' || map[p.y][p.x - 1] == ' ' ||
					map[p.y - 1][p.x] == ' ')
				{
					printf("Error, map is not closed \
at [%d, %d]\n", p.x + 1, p.y + 1);
					return (1);
				}
			}
		}
	}
	return (0);
}

int	check_map_validity(char **map)
{
	t_veci		pos;
	char		cell;
	int			player_count;

	player_count = 0;
	pos.y = -1;
	while (map[++pos.y] != NULL)
	{
		pos.x = -1;
		while (map[pos.y][++pos.x] != '\0')
		{
			cell = map[pos.y][pos.x];
			if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
			{
				player_count++;
				continue ;
			}
			if (cell == '0' || cell == '1' || cell == ' ')
				continue ;
			printf("Error, invalid character '%c' \
at [%d, %d]\n", cell, pos.x + 1, pos.y + 1);
			return (1);
		}
	}
	if (player_count != 1)
		printf("Error, there must be only one player in the map\n");
	return (is_map_closed(map) && player_count == 1);
}
