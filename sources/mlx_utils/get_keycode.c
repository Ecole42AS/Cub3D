/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:50:28 by astutz            #+#    #+#             */
/*   Updated: 2024/01/03 00:03:10 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*gcc -o mon_programme get_keycode.c
-L/home/alex/Cub3D/minilibx/linux -lmlx -lXext -lX11 -lm*/
int key_hook(int keycode, void *param)
{
    (void)param;
    printf("Key pressed: %d\n", keycode);
    return (0);
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 500, 500, "Keycode Display");

    mlx_key_hook(win, key_hook, NULL);
    mlx_loop(mlx);

    return (0);
}