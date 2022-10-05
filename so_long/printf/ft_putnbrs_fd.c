/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:49:26 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/14 00:25:24 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			count++;
		}
		if (n >= 10)
		{
			count += ft_put_nbr_fd((n / 10), fd);
			count += ft_put_nbr_fd((n % 10), fd);
		}
		else
			count += ft_put_char_fd((n + '0'), fd);
	}
	return (count);
}

int	ft_put_unsnbr_fd(unsigned int n, int fd)
{
	unsigned int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_put_unsnbr_fd((n / 10), fd);
		count += ft_put_unsnbr_fd((n % 10), fd);
	}
	else
		count += ft_put_char_fd((n + '0'), fd);
	return (count);
}
