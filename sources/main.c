/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:15:29 by astutz            #+#    #+#             */
/*   Updated: 2023/11/04 09:10:51 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx_data *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bpp / 8));
	*(unsigned int*)dst = color;
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_mlx_data	*mlx;
	t_vector	*vector;
	int			color;
	
	mlx = ft_malloc_failed_msg(1, sizeof(t_mlx_data));
	vector = ft_malloc_failed_msg(1, sizeof(t_vector));
	color =	0x00FF0000;
	vector->x = 5; // a initialiser 
	vector->y = 5;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT, "Cub3D");
	mlx->img = mlx_new_image(mlx->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	my_mlx_pixel_put(mlx, vector->x, vector->y, color);
	mlx_put_image_to_window(mlx, mlx->mlx_win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
    
	// int fd = open("/Users/astutz/42cursus/cub3D/test.txt", O_RDONLY);

	// if (fd == -1)
	// {
	// 	ft_putstr_fd(strerror(errno), 2);
	// 	return(1);
	// }

    // char *line;
    // while ((line = gnl_unempty(fd)) != NULL)
	// {
	// 	if (line[strlen(line) - 1] == '\n')
    //         line[strlen(line) - 1] = '\0';
    //     printf("Ligne non vide : %s\n", line);
    //     free(line);
    // }

    // close(fd);

//     return 0;
}


// #include "../includes/cub3d.h"

// int main(int ac, char **av)
// {
//     (void)ac;
//     (void)av;

//     t_mlx_data mlx; // Créez une instance de la structure t_mlx_data
//     t_vector vector; // Créez une instance de la structure t_vector

//     int color = 0x00FF0000;
//     vector.x = 5; // Initialisez les membres de la structure
//     vector.y = 5;

//     mlx.mlx = mlx_init();
//     mlx.mlx_win = mlx_new_window(mlx.mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT, "Cub3D");
//     mlx.img = mlx_new_image(mlx.mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
//     mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_length, &mlx.endian);

//     my_mlx_pixel_put(&mlx, vector.x, vector.y, color); // Passez un pointeur vers la structure mlx

//     mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
//     mlx_loop(mlx.mlx);

//     return 0;
// }
