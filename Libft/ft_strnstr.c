/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:35:47 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:28:25 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	k;

	if (needle[0] == 0)
		return ((char *)haystack);
	if (n == 0)
		return (NULL);
	i = 0;
	k = 0;
	while (haystack[i] && i < n)
	{
		k = 0;
		while (needle[k] == haystack[i + k] && i + k < n)
		{
			if (needle[k + 1] == 0)
				return ((char *)&haystack[i]);
			k++;
		}
		i++;
	}
	return (NULL);
}
