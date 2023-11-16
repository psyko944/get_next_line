/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:17:18 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/16 19:59:12 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	while (len--)
		*d++ = *s++;
	return (dest);
}

char *ft_join(char *save, char *buffer)
{
	char *tmp;

	tmp = ft_strjoin(save, buffer);
	free(save);
	return (tmp);
}

char *ft_tmp_substr(char *next, char *offset)
{
	char *tmp;

	tmp = ft_substr(next, ft_strlen(next) - ft_strlen(offset) + 1, ft_strlen(next));
	free(next);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char *next;
	char	*offset;
	if (fd < 0 || BUFFER_SIZE < 1)
		return NULL;
	next = ft_read(fd, next);
	if (!next)
		return (NULL);
	if (ft_strchr(next, '\n'))
	{
		offset = ft_strchr(next, '\n');
		line = ft_substr(next, 0, ft_strlen(next) - ft_strlen(offset));
		next = ft_tmp_substr(next, offset);
	}
	return (line);
}

char *ft_read(int fd, char *save)
{
	char	*buffer;
	ssize_t	rv;

	if (!save)
		save = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	rv = BUFFER_SIZE;
	while (rv > 0)
	{
		rv = read(fd, buffer, BUFFER_SIZE);
		if (rv == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rv] = '\0';
		save = ft_join(save, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (save);
}

/*int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	char *s;
	for (int i = 0;i < 5;i++)
	{
		s = get_next_line(fd);
		printf("%s\n", s);
		free(s);
	}
	close(fd);
	return (0);
}*/
