/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:12:40 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/09 10:15:26 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formato(char a, va_list argumentos)
{
	g_c = 0;
	if (a == '%')
		g_c = ft_putchar('%');
	if (a == 'c')
		g_c = ft_putchar(va_arg(argumentos, int));
	if (a == 's')
		g_c = ft_putstr(va_arg(argumentos, char *));
	if (a == 'p')
	{
		g_c = write(1, "0x", 2);
		g_c = ft_pp(va_arg(argumentos, unsigned long), "0123456789abcdef");
	}
	if (a == 'd')
		g_c = ft_putnbr(va_arg(argumentos, int));
	if (a == 'i')
		g_c = ft_putnbr(va_arg(argumentos, int));
	if (a == 'u')
		g_c = ft_uh(va_arg(argumentos, unsigned int), "0123456789");
	if (a == 'x')
		g_c = ft_uh(va_arg(argumentos, unsigned int), "0123456789abcdef");
	if (a == 'X')
		g_c = ft_uh(va_arg(argumentos, unsigned int), "0123456789ABCDEF");
	return (g_c);
}

//a = *pointer, i = comprimento
int	ft_printf(const char *string, ...)
{
	va_list	argumentos;
	char	*a;
	int		contador;

	contador = 0;
	va_start(argumentos, string);
	a = (char *)string;
	while (a[0] != '\0')
	{
		if (a[0] == '%')
		{
			contador += formato(a[1], argumentos);
			a++;
		}
		else
			contador += ft_putchar(*a);
		a++;
	}
	va_end(argumentos);
	return (contador);
}
