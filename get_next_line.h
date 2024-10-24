/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   get_next_line.h                                .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid>      |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/10/16 16:11:21 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/10/24 17:49:03 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//read, close
# include <unistd.h>
//open
# include <fcntl.h>
//printf
# include <stdio.h>
//malloc and free
# include <stdlib.h>
//SIZE_MAX
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);

char	*ft_strnappend(char *dest, char *src, size_t nb);
long	ft_find_lbreak(char *string);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
#endif
