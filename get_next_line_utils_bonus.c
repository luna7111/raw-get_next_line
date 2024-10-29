/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   get_next_line_utils.c                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.c     |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/10/17 16:40:04 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/10/23 13:07:49 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen > size)
		return (srclen + size);
	dst += dstlen;
	size -= dstlen;
	while (size-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (srclen + dstlen);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*allocated_memory;
	size_t	i;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	i = size * nmemb;
	allocated_memory = (char *)malloc(nmemb * size);
	if (!allocated_memory)
		return (NULL);
	while (i-- > 0)
		allocated_memory[i] = '\0';
	return (allocated_memory);
}
