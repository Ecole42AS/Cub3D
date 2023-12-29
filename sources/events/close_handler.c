/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:23:05 by lray              #+#    #+#             */
/*   Updated: 2023/12/29 23:38:44 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_handler(int keycode, void *param)
{
	t_vars *vars = param;

	(void)keycode;
	if (vars == NULL || vars->mlx == NULL || vars->win == NULL) {
		printf("Invalid vars in close_handler\n");
		return (1);
	}
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
