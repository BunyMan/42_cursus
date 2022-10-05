/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:03:49 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/08/12 17:16:08 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	else
		return (0);
}

static int	ft_wordcount(const char *str, char c)
{
	int		words;
	size_t	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (ft_space(str[i], c) == 0 && ft_space(str[i + 1], c) == 1)
			words++;
		i++;
	}
	return (words);
}

static int	split_it(char const *s, char c, int st, char **ns)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s[++i])
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
			st++;
		}
		if (ft_space(s[i], c) == 0 && ft_space(s[i + 1], c) == 1)
		{
			ns[j] = ft_substr(s, st, (i - st) + 1);
			if (!ns[j])
				return (0);
			st = i + 1;
			j++;
		}
	}
	ns[j] = NULL;
	return (1);
}

void	*freematrix(char **ns, int msize)
{
	while (msize--)
		free(ns[msize]);
	free(ns);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**ns;
	size_t	st;
	int		matlen;

	st = 0;
	if (!s)
		return (NULL);
	matlen = ft_wordcount(s, c);
	//printf("words %d\n", matlen);
	ns = ft_calloc(matlen + 1, sizeof(char *));
	if (!ns)
		return (NULL);
	if (!split_it(s, c, st, ns))
		return (freematrix(ns, matlen));
	return (ns);
}
