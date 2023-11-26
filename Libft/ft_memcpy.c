/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:27:26 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:28:07 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src_cpy;
	unsigned char		*dst_cpy;

	i = 0;
	src_cpy = src;
	dst_cpy = dst;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (i < n)
	{
		dst_cpy[i] = (unsigned char)src_cpy[i];
		i++;
	}
	return (dst);
}
