/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:39:12 by lray              #+#    #+#             */
/*   Updated: 2024/02/14 00:11:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	valide_celle(char cell, int *player_count);
static void	init_player(t_ctx *ctx, t_veci pos, char cell);
static int	valide_player(int *player_count);

int	check_map_validity(t_ctx *ctx)
{
	t_veci	pos;
	int		player_count;
	char	cell;

	player_count = 0;
	pos.y = -1;
	memset(&ctx->map->map_size, 0, sizeof(ctx->map->map_size));
	while (ctx->map->data[++pos.y] != NULL)
	{
		ctx->map->map_size.y++;
		pos.x = -1;
		while (ctx->map->data[pos.y][++pos.x] != '\0')
		{
			cell = ctx->map->data[pos.y][pos.x];
			if (!valide_celle(cell, &player_count))
				return (0);
			if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
				init_player(ctx, pos, cell);
		}
		if (pos.x > ctx->map->map_size.x)
			ctx->map->map_size.x = pos.x;
	}
	if (!valide_player(&player_count))
		return (0);
	return (1);
}

static int	valide_celle(char cell, int *player_count)
{
	if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
	{
		(*player_count)++;
		return (1);
	}
	if (cell == '0' || cell == '1' || cell == ' ')
		return (1);
	ft_putstr_fd("Error, invalid character\n", 2);
	return (0);
}

void	init_player(t_ctx *ctx, t_veci pos, char cell)
{
	if (cell == 'N')
		player_init(&ctx->player, (t_vec){pos.x + 0.5, pos.y + 0.5}, \
		(t_vec){0, -1}, (t_vec){-0.66, 0});
	else if (cell == 'S')
		player_init(&ctx->player, (t_vec){pos.x + 0.5, pos.y + 0.5}, \
		(t_vec){0, 1}, (t_vec){0.66, 0});
	else if (cell == 'E')
		player_init(&ctx->player, (t_vec){pos.x + 0.5, pos.y + 0.5}, \
		(t_vec){-1, 0}, (t_vec){0, 0.66});
	else if (cell == 'W')
		player_init(&ctx->player, (t_vec){pos.x + 0.5, pos.y + 0.5}, \
		(t_vec){1, 0}, (t_vec){0, -0.66});
}

static int	valide_player(int *player_count)
{
	if (*player_count != 1)
	{
		ft_putstr_fd("Error, exactly one player must be on the map\n", 2);
		return (0);
	}
	return (1);
}
