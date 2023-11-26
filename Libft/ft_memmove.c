/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:36:54 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:28:08 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*src_cpy;
	unsigned char		*dst_cpy;
	size_t				i;

	i = len;
	src_cpy = src;
	dst_cpy = dst;
	if (dst > src)
	{
		while (i > 0)
		{
			dst_cpy[i - 1] = src_cpy[i - 1];
			i--;
		}
		return (dst_cpy);
	}
	else
		return (ft_memcpy(dst, src, len));
}
