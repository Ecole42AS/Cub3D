/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:16:34 by lray              #+#    #+#             */
/*   Updated: 2023/11/19 16:17:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_pixel(t_image *img, int x, int y)
{
	char	*src;

	src = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int*)src);
}
