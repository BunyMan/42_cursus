/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:42:42 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/10/22 18:57:01 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	leneedle;

	leneedle = ft_strlen(needle);
	if (leneedle == 0)
		return ((char *)haystack);
	if (haystack[0] == '\0')
		return (NULL);
	while (leneedle <= len)
	{
		if (ft_strncmp(haystack, needle, leneedle) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
