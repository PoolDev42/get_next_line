/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:20:00 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/28 22:00:51 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>
char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	static char		*remainder = NULL;
	char			*line;
	static int		nb_bytes = 0;

	if (nb_bytes <= 0)
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
	if (!nb_bytes)
		return (NULL);
	if (!remainder)
		remainder = strdup(buffer);
	else
	{
		remainder = strchr(remainder, '\n');
		if (!remainder)
			return (NULL);
	}
	buffer[nb_bytes] = '\0';
	if (remainder[0] == '\n')
		remainder++;
	line = ft_substr(remainder, 0, find_next_null(remainder) + 1);
	if (!line)
		return (NULL);
	return (line);
}

#include <fcntl.h>
int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char* line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}