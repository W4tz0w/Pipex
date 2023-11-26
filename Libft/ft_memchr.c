/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:58:05 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:18:53 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cast;
	size_t			i;

	i = 0;
	cast = (unsigned char *)s;
	while (i < n)
	{
		if (*cast == (unsigned char)c)
			return (cast);
		cast++;
		i++;
	}
	return (NULL);
}
