#ifndef CUB3D_H
# define CUB3D_H

#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 600

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "mlx.h"

#include "structures.h"
#include "mlx_utils.h"
#include "colors.h"
#include "events.h"
#include "ctx.h"
#include "win.h"
#include "gameloop.h"
#include "player.h"
#include "ray.h"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_mlx_data;

    // mlx_ptr = mlx_init();
    // win_ptr = mlx_new_window(mlx_ptr, width, height, "Ma Fenêtre Minilibx");
    // image_ptr = mlx_new_image(mlx_ptr, width, height);
    // data_ptr = mlx_get_data_addr(image_ptr, &bits_per_pixel, &size_line, &endian);

    // // Utilisez ces structures pour dessiner et gérer votre application Minilibx

    // mlx_loop(mlx_ptr);
    // return 0;
// }


typedef struct s_parsing
{
	char	**parsed_lines;
}			t_parsing;

char	*gnl_unempty(int fd);
int		open_file(char *file);

#endif
