/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:22:56 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:28:14 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			wc++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (wc);
}

static char	*ft_cut(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		j;

	j = 0;
	i = 0;
	splitted = malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (!splitted)
		return (NULL);
	while (s && s[i])
	{
		if (s[i] != c)
		{
			splitted[j] = ft_cut(s + i, c);
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	splitted[j] = NULL;
	return (splitted);
}

// int main()
// {
// 	char **split = ft_split("      split       this for   me  !       ", ' ');
// 	int	j;
// 	j = 0;
// 	while (split[j])
// 	{
// 		printf("-> %s\n", split[j]);
// 		j++;
// 	}
// }
