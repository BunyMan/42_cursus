/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:30:08 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/05 15:35:35 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//linha a retornar, se nao houver nova linha retorna nulo, vai para o fim do
//ficheiro, malloc para o fim do ficheiro, linha = buffer, substitui \0 por \n
char	*ft_linha(char *buffer)
{
	int		i;
	int		j;
	char	*linha;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	linha = ft_calloc(i + 2, sizeof(char));
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		linha[j] = buffer[j];
		j++;
	}
	if (buffer[j] && buffer[j] == '\n')
		linha[j++] = '\n';
	return (linha);
}

// encontra o len da linha, se o fim da linha for \0 retorna nulo, len do
// ficheiro = len da linha + 1, linha = buffer.
char	*ft_proxima(char *buffer)
{
	int		a;
	int		b;
	char	*linha;

	a = 0;
	while (buffer[a] && buffer[a] != '\n')
		a++;
	if (!buffer[a])
	{
		free(buffer);
		return (NULL);
	}
	linha = ft_calloc((ft_strlen(buffer) - a + 1), sizeof(char));
	a++;
	b = 0;
	while (buffer[a])
		linha[b++] = buffer[a++];
	free(buffer);
	return (linha);
}

//free e join
char	*fr_free(char *buffer, char *res)
{
	char	*temp;

	temp = ft_strjoin(buffer, res);
	free(buffer);
	return (temp);
}

//malloc se o resto nao existir, malloc do buffer, enquanto nao esta
//no fim do ficheiro fica a ler, para se encontrar \n
char	*leitor(int fd, char *resto)
{
	char	*buffer;
	int		leitor;

	if (!resto)
		resto = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	leitor = 1;
	while (leitor > 0)
	{
		leitor = read(fd, buffer, BUFFER_SIZE);
		if (leitor == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[leitor] = 0;
		resto = fr_free(resto, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (resto);
}

//usa o [OPEN_MAX] da biblioteca <limits.h> que lhe permite ter o número
//máximo de processos abertos de maneira a que possa abrir vários fd 
//ao mesmo tempo
char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*linha;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = leitor(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	linha = ft_linha(buffer[fd]);
	buffer[fd] = ft_proxima(buffer[fd]);
	return (linha);
}
