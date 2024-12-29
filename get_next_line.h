/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:41:34 by mekherbo          #+#    #+#             */
/*   Updated: 2024/12/28 14:00:31 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_LIMIT
#  define FD_LIMIT FOPEN_MAX
# endif

/*      gnl_functions                    */
char	*get_next_line(int fd);

/*      libc functions                        */
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	ft_bzero(void *s, size_t n);
#endif
