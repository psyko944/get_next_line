/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:27:38 by mekherbo          #+#    #+#             */
/*   Updated: 2024/12/29 19:14:28 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = -1;
	while (s2[++j])
		join[i++] = s2[j];
	join[i] = '\0';
	free((char *)s1);
	return (join);
}

static void	cut(char *line, char *keep)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strchr(line, '\n') - line;	
	while (line[i++])
	{
		keep[j] = line[i];
		j++;
	}
	line[ft_strchr(line, '\n')-line + 1] = '\0';
	keep[j] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	keep[FD_LIMIT][BUFFER_SIZE + 1] = {0};

	line = NULL;
	if (fd < 0 || fd > FD_LIMIT)
		return (NULL);
	if (*keep[fd] != 0)
	{
		line = ft_strdup(keep[fd]);
		if (ft_strchr(line, '\n'))
			return (cut(line, keep[fd]), line);
	}
	ft_bzero(keep[fd], BUFFER_SIZE + 1);
	while (read(fd, keep[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin2(line, keep[fd]);
		if (ft_strchr(line, '\n'))
			return (cut(line, keep[fd]), line);
		ft_bzero(keep[fd], BUFFER_SIZE + 1);
	}
	return (line);
}