/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:41:34 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/18 12:46:50 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
char	*ft_read(int fd, char *save);
char	*ft_new_save(char *save);
char	*ft_get_line(char *save);

/*      libc functions                        */
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s1);

#endif
