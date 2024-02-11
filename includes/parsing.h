/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:35:41 by astutz            #+#    #+#             */
/*   Updated: 2024/02/10 14:07:20 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

char				*gnl_unempty(int fd);
int					open_file(char *file_path);
void				free_split(char **split_result);
void				free_texture(t_texture *texture);
int					parse_texture_paths(t_texture *texture, int fd);
void				parse_colors(int fd, t_color *color);
int					get_map_line_number(char *file_path);
void				free_map(char **map);
char				**map_parsing(int fd, char	*file_path);
int					get_map_line_number(char *file_path);
int					is_map_closed(char **map);
int					check_map_validity(char **map);
int					parser(char *file_path, t_parsing_data *data);
void				texture_path_setter(t_texture *texture, const char *path, const char *prefix);
int					parsing_data_init(t_parsing_data *data);
// void				color_init(t_color *color);


#endif
