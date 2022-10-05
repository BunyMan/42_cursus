/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strljoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:43:34 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/12/01 17:44:43 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strljoin(char const *s1, char const *s2, unsigned int len)
{
	char			*ns;
	unsigned int	i;
	unsigned int	j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_substr(s2, 0, len));
	ns = malloc((ft_strlen(s1) + len) * sizeof(char) + 1);
	if (!ns)
		return (NULL);
	i = -1;
	while (s1[++i])
		ns[i] = s1[i];
	j = -1;
	while (s2[++j] && j < len)
		ns[i + j] = s2[j];
	ns[i + j] = '\0';
	return (ns);
}
