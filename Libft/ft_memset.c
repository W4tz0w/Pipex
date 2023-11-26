/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:33:31 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:28:09 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *dest, int c, size_t len)
{
	char		*destcast;
	size_t		i;

	i = 0;
	destcast = (char *)dest;
	while (i < len)
	{
		destcast[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
