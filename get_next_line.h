#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

int		find_next_null(char *s);

char    *ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

#endif