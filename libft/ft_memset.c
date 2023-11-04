/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:11:54 by astutz            #+#    #+#             */
/*   Updated: 2022/11/09 20:19:11 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

// void *memset(void *str, int c, size_t len)
// {
// 	unsigned char *ptr;

// 	ptr = str;
// 	while (len > 0)
// 	{
// 		*ptr = c;
// 		ptr++;
// 		len--;
// 	}
// }

// void	*ft_memset(void *str, int c, size_t n)
// {
// 	size_t		idx;

// 	idx = 0;
// 	while (idx < n)
// 	{
// 		*((unsigned char *)str + idx) = c;
// 		idx++;
// 	}
// 	return (str);
// }

void	*ft_memset(void *s, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
