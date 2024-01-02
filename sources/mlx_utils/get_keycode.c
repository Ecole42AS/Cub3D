/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:50:28 by astutz            #+#    #+#             */
/*   Updated: 2024/01/02 13:50:44 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx/linux/mlx.h"
#include <stdio.h>

int key_hook(int keycode, void *param)
{
    (void)param;
    printf("Key pressed: %d\n", keycode);
    return (0);
}

// int main(void)
// {
//     void *mlx;
//     void *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 500, 500, "Keycode Display");

//     mlx_key_hook(win, key_hook, NULL);
//     mlx_loop(mlx);

//     return (0);
// }