/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:33:02 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/05/26 09:32:25 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (str && *str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			is_n;
	long int	rest;

	i = 0;
	is_n = 1;
	rest = 0;
	if (str[0] == '0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_n *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		rest = (rest * 10) + (str[i] - '0');
		i++;
	}
	return (rest * is_n);
}
