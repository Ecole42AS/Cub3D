/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:04:27 by astutz            #+#    #+#             */
/*   Updated: 2024/01/27 10:04:56 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void print_map(char **map, t_veci map_size) {
//     printf("Printed Map:\n");
//     for (int i = 0; i < map_size.y; i++) {
//         for (int j = 0; j < map_size.x; j++) {
//             printf("%c", map[i][j]);
//         }
//         printf("\n");
//     }
// }

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

