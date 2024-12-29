/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:03:22 by mekherbo          #+#    #+#             */
/*   Updated: 2024/12/28 15:45:43 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdint.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
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

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s) + 1;
	res = malloc(sizeof(char) * (len));
	if (!res)
		return (NULL);
	int i = -1;
	while (s[++i])
		res[i] = s[i];
	res[i] = 0;
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i++] = 0;
	}
}