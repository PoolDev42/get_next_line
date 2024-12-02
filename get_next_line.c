/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:20:00 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/02 10:57:27 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

static char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		firstindex;
	char	*b;

	b = (char *) s;
	i = ft_strlen(s);
	firstindex = -1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			firstindex = i;
		i--;
	}
	if (firstindex == -1)
		return ((void *)0);
	return (b + firstindex);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1] = {0};
	char			*line;
	int				index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index = 1;
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (index > 0 && !ft_strchr(line, '\n'))
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index == -1)
			return (ft_bzero(buffer, BUFFER_SIZE), free(line), NULL);
		buffer[index] = '\0';
		line = ft_strjoin_free(line, buffer);
		if (!line)
			return (NULL);
	}
	if (index == 0 && !line[0])
		return (free(line), NULL);
	ft_update(buffer);
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}*/