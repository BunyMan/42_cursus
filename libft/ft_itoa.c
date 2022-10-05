/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:10:13 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/10/26 16:48:22 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printnum(int n)
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
