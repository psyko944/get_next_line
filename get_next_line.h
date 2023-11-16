/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:41:34 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/16 18:34:45 by mekherbo         ###   ########.fr       */
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
#  define FD_LIMIT 256
# endif

/*      gnl_functions                    */
char	*ft_read(int fd, char *save);
//char	*read_runtime(int fd, char *res, char *read_buffer);
//char	*read_line(int fd, char **fd_save, char *read_buffer);

/*      functions                        */
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s1);
void	*ft_calloc(size_t count, size_t size);
char	*ft_join(char *save, char *buffer);
char	*ft_tmp_substr(char *next, char *offset);
void	*ft_memcpy(void *dest, const void *src, size_t len);
#endif
