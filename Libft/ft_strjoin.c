/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:45:39 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:28:18 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	ptr = malloc(sizeof(char) * (i + j + 1));
	if (!ptr)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		ptr[i] = s1[i];
	j = -1;
	while (s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	return (ptr);
}

// int	main()
// {
// 	char	*s1 = "Mange ma bite";
// 	char	*s2 = "...stp";
// 	printf("Mon ft : %s\n", ft_strjoin(s1, s2));
// 	return(0);
// }
