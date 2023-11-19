/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:10:14 by lray              #+#    #+#             */
/*   Updated: 2023/11/19 16:36:40 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

void	put_pixel(t_image *img, int x, int y, int color);
int		get_pixel(t_image *img, int x, int y);
void	put_img_to_img(t_image *dst, t_image *src, int x, int y);
t_image	*img_create(void *mlx, int width, int height);

#endif
