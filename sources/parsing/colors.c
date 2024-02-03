/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:31:21 by astutz            #+#    #+#             */
/*   Updated: 2024/02/03 14:13:51 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*◦ Si un problème de configuration de n’importe quel type est rencontré dans
le fichier, le programme doit quitter et renvoyer "Error\n" suivi d’un message
d’erreur explicite de votre choix.*/
void	parse_colors(int fd, t_color *color)
{
	char	**split_result;
	char	**split_colors;
	char	*line;

	line = gnl_unempty(fd);
	split_result = ft_split(line, ' ');
	split_colors = ft_split(split_result[1], ',');
	color_init(color);
	if (!ft_strcmp(split_result[0], "F"))
	{
		color->rgb_floor[1] = (unsigned int)ft_atoi(split_colors[0]);
		color->rgb_floor[2] = (unsigned int)ft_atoi(split_colors[1]);
		color->rgb_floor[3] = (unsigned int)ft_atoi(split_colors[2]);
	}
	free(line);
	free_split(split_result);
	free_split(split_colors);
	line = gnl_unempty(fd);
	split_result = ft_split(line, ' ');
	split_colors = ft_split(split_result[1], ',');
	if (!ft_strcmp(split_result[0], "C"))
	{
		color->rgb_ceiling[1] = (unsigned int)ft_atoi(split_colors[0]);
		color->rgb_ceiling[2] = (unsigned int)ft_atoi(split_colors[1]);
		color->rgb_ceiling[3] = (unsigned int)ft_atoi(split_colors[2]);
	}
}
