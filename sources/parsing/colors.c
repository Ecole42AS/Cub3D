/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:31:21 by astutz            #+#    #+#             */
/*   Updated: 2024/02/11 11:24:42 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*◦ Si un problème de configuration de n’importe quel type est rencontré dans
le fichier, le programme doit quitter et renvoyer "Error\n" suivi d’un message
d’erreur explicite de votre choix.*/
// void	parse_colors(int fd, t_color *color)
// {
// 	char	**split_result;
// 	char	**split_colors;
// 	char	*line;

// 	line = gnl_unempty(fd);
// 	split_result = ft_split(line, ' ');
// 	split_colors = ft_split(split_result[1], ',');
// 	if (!ft_strcmp(split_result[0], "F"))
// 		color->rgb_floor = clr_make_trgb(0, ft_atoi(split_colors[0]), ft_atoi(split_colors[1]), ft_atoi(split_colors[2]));
// 	free(line);
// 	free_split(split_result);
// 	free_split(split_colors);
// 	line = gnl_unempty(fd);
// 	split_result = ft_split(line, ' ');
// 	split_colors = ft_split(split_result[1], ',');
// 	if (!ft_strcmp(split_result[0], "C"))
// 		color->rgb_ceiling = clr_make_trgb(0, ft_atoi(split_colors[0]), ft_atoi(split_colors[1]), ft_atoi(split_colors[2]));
// }

static int extract_color_components(char *str, int *r, int *g, int *b) {
    char **split = ft_split(str, ',');
    if (!split)
        return 1;
    if (split[0] && split[1] && split[2]) {
        *r = ft_atoi(split[0]);
        *g = ft_atoi(split[1]);
        *b = ft_atoi(split[2]);
        free_split(split);
        return 0;
    }
    free_split(split);
    return 1;
}

static int parse_color_string(char *str) {
    int r, g, b;
    return !extract_color_components(str, &r, &g, &b) ? clr_make_trgb(0, r, g, b) : 1;
}

void parse_colors(int fd, t_color *color) {
    char *line;
    char **split_result;
    char **split_colors;
    int count;

    count = -1;
    while (++count < 2 && (line = gnl_unempty(fd)) != NULL) {
        split_result = ft_split(line, ' ');
        if (!split_result) {
            free(line);
            continue;
        }
        split_colors = ft_split(split_result[1], ',');
        if (!split_colors) {
            free_split(split_result);
            free(line);
            continue;
        }
        if (!ft_strcmp(split_result[0], "F"))
            color->rgb_floor = parse_color_string(split_result[1]);
        else if (!ft_strcmp(split_result[0], "C"))
            color->rgb_ceiling = parse_color_string(split_result[1]);
        free_split(split_result);
        free_split(split_colors);
        free(line);
    }
}

