/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:02:37 by lray              #+#    #+#             */
/*   Updated: 2024/01/09 14:22:26 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

#include "structures.h"

void	ctx_init(t_ctx *ctx, int width, int height, char *name);
void	ctx_show(t_ctx *ctx);
void	ctx_free(t_ctx *ctx);

#endif
