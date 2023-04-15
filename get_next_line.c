/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:10:32 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/13 11:31:26 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*des;

	if (size > 0 && count > ULONG_MAX / size)
		return (NULL);
	des = (void *)malloc(count * size);
	if (des == NULL)
		return (NULL);
	ft_bzero (des, count * size);
	return (des);
}

static char	*restmex(char *textmex)
{
	size_t	len;
	int		y;
	char	*rest;

	len = 0;
	y = 0;
	while (textmex[y] && textmex[y] != '\n')
		y++;
	if (textmex[y] == '\0')
	{
		free (textmex);
		return (NULL);
	}
	len = ft_strlen(textmex);
	len = len - y;
	rest = ft_substr(textmex, (y + 1), len);
	free(textmex);
	return (rest);
}

static char	*line(char *textmex)
{
	int		x;
	char	*lectura;

	x = 0;
	if (!textmex)
		return (NULL);
	while (textmex[x] != '\n' && textmex[x] != '\0')
		x++;
	lectura = ft_substr(textmex, 0, x + 1);
	return (lectura);
}

char	*ft_clean(char **rest, char **buffer)
{
	free(*rest);
	free(*buffer);
	*rest = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*rest;
	char		*lectura;
	int			x;

	x = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!rest)
		rest = ft_calloc(1, sizeof(char));
	while (x != 0 && ft_strchr(rest, '\n') == 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == -1)
			return (ft_clean(&rest, &buffer));
		buffer[x] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	if (!rest)
		return (NULL);
	free(buffer);
	lectura = line(rest);
	rest = restmex(rest);
	return (lectura);
}
