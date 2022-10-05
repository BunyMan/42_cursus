/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:18:53 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/14 00:08:07 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*throw_it(char **storage)
{
	char	*return_of_the_string;
	int		i;
	char	*intern;

	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i] != '\0')
		i++;
	return_of_the_string = ft_substr(*storage, 0, i + 1);
	intern = NULL;
	if ((*storage)[i] == '\n' && (*storage)[i + 1] != '\0')
	{
		intern = ft_substr(*storage, i + 1, ft_strlen(*storage) - i);
		free(*storage);
		*storage = ft_strdup(intern);
		free(intern);
		intern = NULL;
	}
	else
	{
		free(*storage);
		*storage = NULL;
	}
	return (return_of_the_string);
}

static char	*morph(char **storage, char *string)
{
	int		i;
	char	*return_of_the_string;
	char	*intern;

	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i] != '\0')
		i++;
	intern = ft_strljoin(string, *storage, i + 1);
	free(string);
	return_of_the_string = ft_strdup(intern);
	free(intern);
	if ((*storage)[i] == '\n' && (*storage)[i + 1] != '\0')
	{
		intern = ft_substr(*storage, i + 1, ft_strlen(*storage) - i);
		free(*storage);
		*storage = ft_strdup(intern);
		free(intern);
		intern = NULL;
	}
	else
	{
		free(*storage);
		*storage = NULL;
	}
	return (return_of_the_string);
}

static char	*read_em_and_weep(int fd, char **storage)
{
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	int			chomp;

	chomp = read(fd, buffer, BUFFER_SIZE);
	if (chomp <= 0)
	{
		if (*storage != NULL)
			free(*storage);
		*storage = NULL;
		return (NULL);
	}
	buffer[chomp] = '\0';
	*storage = ft_strdup(buffer);
	while (chomp > 0 && !ft_strchr(buffer, '\n'))
	{
		chomp = read(fd, buffer, BUFFER_SIZE);
		buffer[chomp] = '\0';
		temp = ft_strljoin(*storage, buffer, ft_strlen(buffer));
		free(*storage);
		*storage = ft_strdup(temp);
		free(temp);
	}
	return (*storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*string;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	string = NULL;
	if (storage)
	{
		string = throw_it(&storage);
		if (ft_strchr(string, '\n'))
			return (string);
	}
	storage = read_em_and_weep(fd, &storage);
	if (!storage && !string)
		return (NULL);
	if (storage)
		string = morph(&storage, string);
	return (string);
}
