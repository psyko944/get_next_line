/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:03:22 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/16 19:51:11 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	char	*cpy;
	size_t	n;
	if ((size * count < size || size * count < count)
		&& (count != 0 && size != 0))
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	cpy = (char *)str;
	n = count * size;
	while (n)
	{
		*cpy = '\0';
		cpy++;
		n--;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;
	
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	join[i] = '\0';
	//free((char *)s1);
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	s = s + start;
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	newstr = ft_calloc(1, len + 1);
	if (!newstr)
		return (0);
	return ((char *)ft_memcpy(newstr, s, len));
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
