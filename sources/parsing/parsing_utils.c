/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:16:20 by astutz            #+#    #+#             */
/*   Updated: 2024/02/11 16:42:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*Get next unempty line of fd*/
char *gnl_unempty(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && ft_strcmp(line, "\n") == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

/*Return fd, -1 if open failed or file is invalid*/
int	open_file(char *file_path)
{
	int fd;

	if (ft_strlen(file_path) <= 4 || ft_strcmp(file_path + ft_strlen(file_path) - 4, ".cub") != 0)
	{
		printf("Error: '%s' should have a '.cub' extension\n", file_path);
		return (-1);
	}
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(file_path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	return (fd);
}

void free_split(char **split_result)
{
	int i;

	i = 0;
    if (split_result)
    {
        while (split_result[i] != NULL)
        {
            free(split_result[i]);
			i++;
        }
        free(split_result);
    }
}

void	free_texture(t_texture *texture)
{
	free(texture->no_texture_path);
	free(texture->so_texture_path);
	free(texture->we_texture_path);
	free(texture->ea_texture_path);
}

void free_map(char **map)
{
    int i;

    if (!map)
        return;

    i = -1;
    while (map[++i])
        free(map[i]);
    free(map);
}


// void color_init(t_color *color)
// {
// 	int i;

// 	i = -1;
//     while (++i < 4)
//     {
//         color->rgb_floor[i] = 0;
//         color->rgb_ceiling[i] = 0;
//     }
// }
