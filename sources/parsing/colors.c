/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:31:21 by astutz            #+#    #+#             */
/*   Updated: 2024/02/12 12:06:31 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*◦ Si un problème de configuration de n’importe quel type est rencontré dans
le fichier, le programme doit quitter et renvoyer "Error\n" suivi d’un message
d’erreur explicite de votre choix.*/

int is_valid_color_format(char *prefix) {
    return (prefix[1] == '\0' && (prefix[0] == 'F' || prefix[0] == 'C'));
}

int parse_color_string(char *str) {
    int r, g, b;
    char **split = ft_split(str, ',');
    if (!split)
        return (-1);
    if (split[0] && split[1] && split[2] && !split[3]) {
        r = ft_atoi(split[0]);
        g = ft_atoi(split[1]);
        b = ft_atoi(split[2]);
        if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) {
            free_split(split);
            return clr_make_trgb(0, r, g, b);
        }
    }
    free_split(split);
    return -1;
}


int assign_color(t_color *color, char *prefix, char *color_string)
{
    int result = parse_color_string(color_string);
    if (result != 1)
    {
        if (!ft_strcmp(prefix, "F"))
            color->rgb_floor = result;
        else if (!ft_strcmp(prefix, "C"))
            color->rgb_ceiling = result;
        return (0);
    }
    else
        return (1);
}

int parse_colors(int fd, t_color *color)
{
    char *line;
    char **split_result;
    char **split_colors;
    int count;
    int parsing_success = 0;

    count = -1;
    while (++count < 2 && (line = gnl_unempty(fd)) != NULL) 
    {
        split_result = ft_split(line, ' ');
        if (!split_result) 
        {
            free(line);
            continue;
        }
        if (!is_valid_color_format(split_result[0])) 
        {
            parsing_success = 1;
            free_split(split_result);
            free(line);
            continue;
        }
        split_colors = ft_split(split_result[1], ',');
        if (!split_colors) 
        {
            parsing_success = 1;
            free_split(split_result);
            free(line);
            continue;
        }
        if(assign_color(color, split_result[0], split_result[1]))
            parsing_success = 1;
        free_split(split_result);
        free_split(split_colors);
        free(line);
    }

    return parsing_success;
}

// int is_valid_color_format(char *prefix) {
//     return (prefix[1] == '\0' && (prefix[0] == 'F' || prefix[0] == 'C'));
// }

// int parse_color_string(char *str) {
//     int r, g, b;
//     char **split = ft_split(str, ',');
//     if (!split)
//         return -1; // Erreur lors du split
//     if (split[0] && split[1] && split[2] && !split[3]) { // Vérifier qu'il y a exactement trois composants RGB
//         r = ft_atoi(split[0]);
//         g = ft_atoi(split[1]);
//         b = ft_atoi(split[2]);
//         if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) { // Vérifier que les composants sont dans la plage valide (0-255)
//             free_split(split);
//             return clr_make_trgb(0, r, g, b); // Générer la couleur RGB
//         }
//     }
//     free_split(split);
//     return -1; // Composants de couleur invalides
// }

// int assign_color(t_color *color, char *prefix, char *color_string) {
//     int result = parse_color_string(color_string);
//     if (result != -1) {
//         if (!ft_strcmp(prefix, "F"))
//             color->rgb_floor = result;
//         else if (!ft_strcmp(prefix, "C"))
//             color->rgb_ceiling = result;
//         return 0;
//     }
//     return 1;
// }

// int parse_colors(int fd, t_color *color) {
//     char *line;
//     char **split_result;
//     char **split_colors;
//     int count;
//     int parsing_success = 0;

//     count = -1;
//     while (++count < 2) {
//         line = gnl_unempty(fd);
//         if (!line)
//             break;
//         split_result = ft_split(line, ' ');
//         free(line);
//         if (!split_result)
//             continue;
//         if (!is_valid_color_format(split_result[0])) {
//             free_split(split_result);
//             continue;
//         }
//         split_colors = ft_split(split_result[1], ',');
//         if (!split_colors) {
//             free_split(split_result);
//             continue;
//         }
//         parsing_success = assign_color(color, split_result[0], split_result[1]);
//         free_split(split_result);
//         free_split(split_colors);
//         if (parsing_success)
//             break;
//     }

//     return parsing_success;
// }
