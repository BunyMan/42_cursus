/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:52:08 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/10/25 19:39:04 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dr;
	const char	*sr;
	size_t		i;

	sr = src;
	dr = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dr < sr)
	{
		while (i < len)
		{
			dr[i] = sr[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dr[len] = sr[len];
	}
	return (dst);
}
