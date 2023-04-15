/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:08:02 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/14 17:32:40 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

void	ft_bzero(void *s, unsigned int n)
{
	char			*dst;
	unsigned int	x;

	dst = s;
	x = 0;
	while (x < n)
	{
		dst[x] = '\0';
		++x;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	k = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(s1)) + (ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1 && s1[i])
		newstr[k++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		newstr[k++] = s2[i++];
	newstr[k] = '\0';
	free((char *)s1);
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	char	*dst;
	size_t	lens;

	x = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen((char *)s);
	if (len == 0 || lens == 0)
		return (NULL);
	if (start >= lens)
		return (NULL);
	if (len > lens - start)
		len = lens - start;
	dst = (char *)malloc(sizeof(char) * (len +1));
	if (!dst)
		return (0);
	while ((start < ft_strlen(s)) && (x < len))
	{
			dst[x] = s[start];
			start++;
			x++;
	}
	dst[x] = '\0';
	return (dst);
}

int	ft_strchr(const char *s, int c)
{
	int		x;
	int		y;

	if (!s)
		return (0);
	x = 0;
	y = ft_strlen(s);
	while (x <= y)
	{
		if (s[x] == (char)c)
		{
			return (1);
		}
		++x;
	}
	return (0);
}
