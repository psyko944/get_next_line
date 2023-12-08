/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:53:01 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/19 21:53:08 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_strchr(const char *str, int c)
{
	char	*retval;
	int		i;

	if (str == NULL)
		return (NULL);
	retval = (char *)str;
	i = 0;
	while (retval[i] != (char)c)
	{
		if (retval[i] == '\0')
			return (0);
		i++;
	}
	return (retval + i);
}
