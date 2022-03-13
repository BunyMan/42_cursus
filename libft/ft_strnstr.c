/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:20:12 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/10/27 14:28:01 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while ((i < len) && (s1[i] != '\0'))
	{
		j = 0;
		while (s1[i + j] == s2[j] && ((i + j) < len))
		{
			if (s2[j + 1] == '\0')
				return ((char *)&(s1[i]));
			j++;
		}
		i++;
	}
	return (0);
}
