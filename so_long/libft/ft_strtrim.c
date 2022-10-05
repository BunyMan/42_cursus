/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:41:24 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/10/28 17:00:55 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trim;
	size_t			len;
	unsigned int	start;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (ft_strchr(set, *(s1 + start)) != 0)
		start++;
	while (ft_strchr(set, *(s1 + len - 1)) != 0)
		len--;
	trim = ft_substr(s1, start, (len - start));
	return (trim);
}
