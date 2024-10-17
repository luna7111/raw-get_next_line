/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   get_next_line.h                                .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid>      |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/10/16 16:11:21 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/10/17 16:54:16 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//read, close
#include <unistd.h>
//open
#include <fcntl.h>
//printf
#include <stdio.h>
//malloc and free
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);

char	*ft_strjoin_butcooler(char *dest, char *src, size_t nb);
size_t	ft_find_lbreak(char *string);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
#endif
