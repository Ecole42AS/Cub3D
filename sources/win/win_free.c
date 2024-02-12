/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:43:35 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 20:36:10 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	win_free(t_win *win)
{
	if (win->win)
	{
		mlx_destroy_window(win->mlx, win->win);
		win->name = "";
		win->width = 0;
		win->height = 0;
		win->mlx = NULL;
	}
	win = NULL;
}
