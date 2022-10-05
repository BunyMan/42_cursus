/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:02:27 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/10/25 19:24:00 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*p;
	const char		*s;

	i = 0;
	if (!dst && !src)
		return (0);
	p = (char *)dst;
	s = (const char *)src;
	while (n--)
	{
		p[i] = s[i];
		i++;
	}
	return (dst);
}
