/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:21:50 by astutz            #+#    #+#             */
/*   Updated: 2024/01/21 13:11:45 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void parse_texture_paths(t_texture *texture, int fd)
{
    char *line;
    char **split_result;

    line = gnl_unempty(fd);
    split_result = ft_split(line, ' ');// vérifier que le split contient bien 2 éléments
    if (!ft_strcmp(split_result[0], "NO") && !split_result[2])
        texture->NO_texture_path = ft_strdup(split_result[1]);
    free(line);
    free_split(split_result);

    line = gnl_unempty(fd);
    split_result = ft_split(line, ' ');
    if (!ft_strcmp(split_result[0], "SO") && !split_result[2])
        texture->SO_texture_path = ft_strdup(split_result[1]);
    free(line);
    free_split(split_result);

    line = gnl_unempty(fd);
    split_result = ft_split(line, ' ');
    if (!ft_strcmp(split_result[0], "WE") && !split_result[2])
        texture->WE_texture_path = ft_strdup(split_result[1]);
    free(line);
    free_split(split_result);

    line = gnl_unempty(fd);
    split_result = ft_split(line, ' ');
    if (!ft_strcmp(split_result[0], "EA") && !split_result[2])
        texture->EA_texture_path = ft_strdup(split_result[1]);
    free_split(split_result);
    free(line);
}

void print_map(char **map, t_veci map_size) {
    printf("Printed Map:\n");
    for (int i = 0; i < map_size.y; i++) {
        for (int j = 0; j < map_size.x; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// int main()
// {
// 	char **map;
//     char *file_path = "/home/alex/Ecole42/Cub3D/maps/test_map.cub";
//     int fd = open_file(file_path);

//     t_texture *texture = ft_calloc(1, sizeof(t_texture));
//     if (!texture)
//     {
//         perror("Erreur lors de l'allocation de la texture");
//         close(fd);
//         return 1;
//     }

// 	t_color *color = ft_calloc(1, sizeof(t_color));
// 	if (!color)
//     {
//         perror("Erreur lors de l'allocation de la couleur");
//         close(fd);
//         return 1;
//     }
	
// 	t_vec_map	map_size;


//     parse_texture_paths(texture, fd);
// 	parse_colors(fd, color);
	
//     printf("Texture nord: %s\n", texture->NO_texture_path);
//     printf("Texture sud: %s\n", texture->SO_texture_path);
//     printf("Texture ouest: %s\n", texture->WE_texture_path);
//     printf("Texture est: %s\n", texture->EA_texture_path);

// 	printf("RGB Floor: %d, %d, %d\n", color->rgb_floor[0], color->rgb_floor[1], color->rgb_floor[2]);
//     printf("RGB Ceiling: %d, %d, %d\n", color->rgb_ceiling[0], color->rgb_ceiling[1], color->rgb_ceiling[2]);	

// 	map = map_parsing(fd, file_path);
// 	if(!map)
// 	{
// 		printf("map parsing error!");
// 		exit (1);
// 	}
// 	else if(check_map_validity(map) == 1)
// 	{
// 		printf("map validity error!");
// 		exit (1);
// 	}
// 	print_map(map, map_size);

	
// 	free_map(map);
// 	free(color);
//     free_texture(texture);
//     close(fd);

//     return 0;
// }


/* --------------------------     code to delete if not usefull    ------------------------------*/
// void parse_and_set_texture_path(t_texture *texture, int fd, const char *identifier) {
//     char *line = gnl_unempty(fd);
//     char **split_result = ft_split(line, ' ');

//     if (split_result && split_result[0] && !ft_strcmp(split_result[0], identifier)) {
//         if (split_result[1]) {
//             if (strcmp(identifier, "NO") == 0) texture->NO_texture_path = ft_strdup(split_result[1]);
//             else if (strcmp(identifier, "SO") == 0) texture->SO_texture_path = ft_strdup(split_result[1]);
//             else if (strcmp(identifier, "WE") == 0) texture->WE_texture_path = ft_strdup(split_result[1]);
//             else if (strcmp(identifier, "EA") == 0) texture->EA_texture_path = ft_strdup(split_result[1]);
//         }
//     }

//     free(line);
//     free_split(split_result);
// }

// void parse_texture_paths(t_texture *texture, int fd) {
//     parse_and_set_texture_path(texture, fd, "NO");
//     parse_and_set_texture_path(texture, fd, "SO");
//     parse_and_set_texture_path(texture, fd, "WE");
//     parse_and_set_texture_path(texture, fd, "EA");
// }



 	// if (!split_result || ft_strcmp(split_result[0], expected_name) != 0)
    // {
    //     perror("Erreur lors de la lecture ou du split de la ligne");
    //     free_split(split_result);
    //     return false;
    // }

	// if (!line || !split_result)
	// {
	// 	perror("Erreur lors de la lecture ou du split de la ligne");
	// 	free(texture);
	// 	free(line);
	// 	free_split(split_result);
	// 	close(fd);
	// 	return 1;
	// }

	// if (!process_texture_line(texture, line, texture_names[i], split_result[1]))
	// {
	// 	free(texture);
	// 	free(line);
	// 	free_split(split_result);
	// 	close(fd);
	// 	return 1;
	// } 
