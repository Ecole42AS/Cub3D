/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:02:37 by lray              #+#    #+#             */
/*   Updated: 2024/01/09 10:43:49 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "structures.h"

void	ctx_init(t_ctx *ctx, int width, int height, char *name);
int		ctx_init_textures(t_ctx *ctx, unsigned int colors[2], char **tex_path);
void	ctx_show(t_ctx *ctx);
void	ctx_free(t_ctx *ctx);

#endif
