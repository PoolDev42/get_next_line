/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:20:21 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/28 19:31:40 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_next_null(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char		*res;
	size_t		i;

	res = malloc(ft_strlen(s) + 1);
	i = 0;
	if (res == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char            *res;
	size_t          j;

	if (!s)
		return (NULL);
	j = 0;
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		res = malloc(ft_strlen(s) - start + 1);
	else
		res = malloc(len * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	while (s[start + j] && len > 0)
	{
		res[j] = s[start + j];
		j++;
		len--;
	}
	res[j] = '\0';
	return (res);
}
