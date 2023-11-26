/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:33:21 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:28:05 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	unsigned char	*cast1;
	unsigned char	*cast2;
	size_t			i;

	i = 0;
	cast1 = (unsigned char *)p1;
	cast2 = (unsigned char *)p2;
	while (i < size)
	{
		if (!(cast1[i] == cast2[i]))
			return ((cast1[i] - cast2[i]));
		i++;
	}
	return (0);
}
