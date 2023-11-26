/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:43:20 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/01/12 18:28:11 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	copy;

	copy = n;
	if (copy == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (copy < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(copy * -1, fd);
	}
	else if (copy > 9)
	{
		ft_putnbr_fd(copy / 10, fd);
		ft_putnbr_fd(copy % 10, fd);
	}
	else
	{
		ft_putchar_fd((char)(copy + 48), fd);
	}
}
