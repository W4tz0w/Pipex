/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:15:48 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:28:28 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;
	size_t		srclen;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
		return ((char *)ft_calloc(1, 1));
	i = 0;
	while (s[start + i] && i < len && (start + i < srclen))
		i++;
	sub = malloc((i + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len && (start + i < srclen))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// int		main(void)
// {
// 	char	*s;
// 	s = "Mange ma bite";
// 	printf("Mon ft : %s\n", ft_substr(s, 0, 13));
// 	// printf("Original ft : %d", substr(s, 0, 15));
// 	return(0);
// }
