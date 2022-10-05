/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:04:26 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/10/24 23:01:04 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	dlen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dlen;
	j = 0;
	if (dlen < dstsize - 1 && dstsize > 0)
	{
		while (src[j] && j + i < (dstsize - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	else if (dlen >= dstsize)
		dlen = dstsize;
	return (dlen + slen);
}
