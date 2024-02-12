/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:04:26 by lray              #+#    #+#             */
/*   Updated: 2024/02/12 14:00:36 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.03

void	go_front(t_ctx *ctx);
void	go_back(t_ctx *ctx);
void	go_left(t_ctx *ctx);
void	go_right(t_ctx *ctx);
void	rotate_left(t_ctx *ctx);
void	rotate_right(t_ctx *ctx);
int		move_is_valide(t_ctx *ctx, double new_x, double new_y);

#endif
