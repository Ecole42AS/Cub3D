/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:35:41 by astutz            #+#    #+#             */
/*   Updated: 2024/02/11 23:15:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

char	*gnl_unempty(int fd);
int		open_file(char *file_path);
void	free_split(char **split_result);
void	free_texture(t_texture *texture);
int		parse_texture_paths(t_texture *texture, int fd);
void	parse_colors(int fd, t_color *color);
int		get_map_line_number(char *file_path);
void	free_map(char **map);
char	**map_parsing(int fd, char	*file_path);
int		get_map_line_number(char *file_path);
int		is_map_closed(char **map);
int		check_map_validity(t_ctx *ctx);
int		parser(char *file_path, t_ctx *ctx);
void	texture_path_setter(t_texture *texture, const char *path, \
	const char *prefix);

#endif
