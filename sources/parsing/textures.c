/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:21:50 by astutz            #+#    #+#             */
/*   Updated: 2024/02/03 14:09:56 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


// if (parse_texture_paths(..) == 1)
// {
// 	free(line);
// 	free_split;
// 	free_texture;
// }

int	parse_texture_paths(t_texture *texture, int fd)
{
    char *line;
    char **split_result;

    line = gnl_unempty(fd);
	if (!line)
		return (1);
    split_result = ft_split(line, ' ');
    if (!ft_strcmp(split_result[0], "NO") && !split_result[2] && !split_result)
		texture->no_texture_path = ft_strdup(split_result[1]);
	else
		return (1);
    free(line);
    free_split(split_result);

	line = gnl_unempty(fd);
	if (!line)
		return (1);
    split_result = ft_split(line, ' ');
    if (!ft_strcmp(split_result[0], "SO") && !split_result[2] && !split_result)
		texture->so_texture_path = ft_strdup(split_result[1]);
	else
		return (1);
    free(line);
    free_split(split_result);

	line = gnl_unempty(fd);
	if (!line)
		return (1);
    split_result = ft_split(line, ' ');
    if (!ft_strcmp(split_result[0], "WE") && !split_result[2] && !split_result)
		texture->we_texture_path = ft_strdup(split_result[1]);
	else
		return (1);
    free(line);
    free_split(split_result);

	line = gnl_unempty(fd);
	if (!line)
		return (1);
    split_result = ft_split(line, ' ');
    if (!ft_strcmp(split_result[0], "EA") && !split_result[2] && !split_result)
		texture->ea_texture_path = ft_strdup(split_result[1]);
	else
		return (1);
    free(line);
    free_split(split_result);
	return (0);
}


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

// ------------------------------Code refracto--------------------------------------
// int parse_and_set_texture(t_texture *texture, int fd, const char *prefix) {
//     char *line = gnl_unempty(fd);
//     if (!line)
//         return 1;

//     char **split_result = ft_split(line, ' ');
//     free(line);

//     if (!split_result || ft_strcmp(split_result[0], prefix) || split_result[2]) {
//         free_split(split_result);
//         return 1;
//     }

//     // Utilisation de la fonction auxiliaire pour définir le chemin de texture
//     texture_path_setter(texture, split_result[1]);

//     free_split(split_result);
//     return 0;
// }

// void texture_path_setter(t_texture *texture, const char *path) {
//     if (!strcmp(prefix, "NO"))
//         texture->NO_texture_path = ft_strdup(path);
//     else if (!strcmp(prefix, "SO"))
//         texture->SO_texture_path = ft_strdup(path);
//     else if (!strcmp(prefix, "WE"))
//         texture->WE_texture_path = ft_strdup(path);
//     else if (!strcmp(prefix, "EA"))
//         texture->EA_texture_path = ft_strdup(path);
// }

// int parse_texture_paths(t_texture *texture, int fd) {
//     const char *prefixes[] = { "NO", "SO", "WE", "EA" };

//     for (int i = 0; i < sizeof(prefixes) / sizeof(prefixes[0]); ++i) {
//         if (parse_and_set_texture(texture, fd, prefixes[i]) != 0)
//             return 1;
//     }

//     return 0;
// }
