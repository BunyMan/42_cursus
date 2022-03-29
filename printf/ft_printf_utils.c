/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 05:07:46 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/15 06:42:27 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int		comp;

	comp = 0;
	if (!s)
		s = "(null)";
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
		comp++;
	}
	return (comp);
}

int	ft_putnbr(int i)
{
	char	*string;
	int		comprimento;

	comprimento = 0;
	string = ft_itoa(i);
	comprimento = ft_putstr(string);
	free (string);
	return (comprimento);
}

//pointer printer
int	ft_pp(unsigned long arg_num, char *string)
{
	int		comprimento;

	comprimento = 0;
	while (string[comprimento])
		comprimento++;
	if (arg_num / comprimento != 0)
	{
		ft_pp((arg_num / comprimento), string);
		g_c += ft_putchar(string[arg_num % comprimento]);
	}
	else
		g_c += ft_putchar(string[arg_num % comprimento]);
	return (g_c);
}

//unsigned hexadecimal
int	ft_uh(long int arg_num, char *string)
{
	int		comprimento;

	comprimento = 0;
	while (string[comprimento])
		comprimento++;
	if (arg_num / comprimento != 0)
	{
		ft_uh((arg_num / comprimento), string);
		g_c += ft_putchar(string[arg_num % comprimento]);
	}
	else
		g_c += ft_putchar(string[arg_num % comprimento]);
	return (g_c);
}
