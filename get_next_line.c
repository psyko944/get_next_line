/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:17:18 by mekherbo          #+#    #+#             */
/*   Updated: 2024/12/29 19:19:56 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	keep[BUFFER_SIZE + 1] = {0};

	line = NULL;
	if (keep[0] != 0)
	{
		line = ft_strdup(keep);
		if (ft_strchr(line, '\n'))
			return (cut(line, keep), line);
	}
	ft_bzero(keep, BUFFER_SIZE + 1);
	while (read(fd, keep, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin2(line, keep);
		if (ft_strchr(line, '\n'))
			return (cut(line, keep), line);
		ft_bzero(keep, BUFFER_SIZE + 1);
	}
	return (line);
}