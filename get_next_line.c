/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:20:00 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/29 12:07:50 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>
char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1] = {0};
	char			*line;
	int				index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index = 1;
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (index > 0 && !strchr(line, '\n'))
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index == -1)
			return (free(line), NULL);
		buffer[index] = '\0';
		line = ft_strjoin_free(line, buffer);
		if (!line)
			return (NULL);
	}
	if (index == 0 && !line[0])
		return (free(line), NULL);
	printf("\n%s\n", buffer);
	ft_update(buffer);
	return (line);
}

#include <fcntl.h>
int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char* line = get_next_line(fd);
	//printf("%s", line);
	free(line);
	line = get_next_line(fd);
	//printf("%s", line);
	free(line);
	line = get_next_line(fd);
	//printf("%s", line);
	free(line);
	line = get_next_line(fd);
	//printf("%s", line);
	free(line);
	line = get_next_line(fd);
	//printf("%s", line);
	free(line);
	close(fd);
	return (0);
}