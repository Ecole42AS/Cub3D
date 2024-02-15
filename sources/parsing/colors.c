/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:31:21 by astutz            #+#    #+#             */
/*   Updated: 2024/02/15 16:14:34 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_color_string(char *str);
static int	extract_color_components(char *str, int *r, int *g, int *b);

void	parse_colors(int fd, t_color *color)
{
	char	*line;
	char	**split_result;
	int		count;

	count = -1;
	while (++count < 2)
	{
		line = gnl_unempty(fd);
		if (line == NULL)
			return ;
		split_result = ft_split(line, ' ');
		free(line);
		if (!split_result)
			continue ;
		if (ft_strcmp(split_result[0], "F") == 0)
			color->rgb_floor = parse_color_string(split_result[1]);
		else if (ft_strcmp(split_result[0], "C") == 0)
			color->rgb_ceiling = parse_color_string(split_result[1]);
		free_split(split_result);
	}
}

static int	parse_color_string(char *str)
{
	int	r;
	int	g;
	int	b;

	if (extract_color_components(str, &r, &g, &b))
		return (clr_make_trgb(0, r, g, b));
	return (0);
}

static int	extract_color_components(char *str, int *r, int *g, int *b)
{
	char	**split;

	split = ft_split(str, ',');
	if (!split)
	{
		ft_putstr_fd("Error while splitting\n", 2);
		return (0);
	}
	if (split[0] && split[1] && split[2])
	{
		*r = ft_atoi(split[0]);
		*g = ft_atoi(split[1]);
		*b = ft_atoi(split[2]);
		free_split(split);
		return (1);
	}
	free_split(split);
	return (0);
}
