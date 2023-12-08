/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:41:34 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/28 16:50:46 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef FD_LIMIT
#  define FD_LIMIT FOPEN_MAX
# endif

/*      gnl_functions                    */
char	*get_next_line(int fd);
char	*ft_read(int fd, char *save);
char	*ft_new_save(char *save);
char	*ft_get_line(char *save);

/*      libc functions                        */
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s1);

#endif
