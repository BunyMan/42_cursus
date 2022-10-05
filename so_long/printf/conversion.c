/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:45:20 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/14 00:24:28 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	dec_hexa(unsigned long n, int fd, char *base)
{
	int				count;
	unsigned long	unsnum;

	unsnum = n;
	count = 0;
	if (unsnum > 15)
	{
		count += dec_hexa((unsnum / 16), fd, base);
		count += ft_put_char_fd(base[unsnum % 16], fd);
	}
	else
		count += ft_put_char_fd(base[unsnum], fd);
	return (count);
}
