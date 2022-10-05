/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:37:30 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/09 01:40:18 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		len;
	char		*p;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen((char *)s1 + start);
	if (len)
		while (s1[len + start - 1] != 0 && ft_strchr(set, s1[len + start - 1]))
			len--;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1 + start, len + 1);
	p[len] = '\0';
	return (p);
}
