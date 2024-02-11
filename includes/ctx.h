/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:02:37 by lray              #+#    #+#             */
/*   Updated: 2024/02/11 18:33:51 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "structures.h"

int		ctx_init(t_ctx *ctx, int win_width, int win_height, char *win_name);
int		ctx_validation(t_ctx *ctx);
int		ctx_init_textures(t_ctx *ctx);
void	ctx_free(t_ctx *ctx);

#endif
