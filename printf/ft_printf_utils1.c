/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:38:18 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/09 09:13:29 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnum(int n)
{
	int	c;

	c = 0;
	if (n == 0)
	{
		c = 1;
		return (c);
	}
	if (n < 0)
		c++;
	while (n)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		b;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	b = printnum(n);
	p = (char *)malloc(sizeof(char) * (b + 1));
	if (p == 0)
		return (0);
	if (n == 0)
		p[0] = '0';
	p[b] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	while (n != 0 && b >= 0)
	{
		p[b-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (s1[size])
		++size;
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
