/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   get_next_line.c                                .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.c     |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/10/17 16:12:55 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/10/17 19:41:35 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_butcooler(char *dest, char *src, size_t nb)
{
	char	*buffer;
	size_t	dest_len;
	size_t	src_len;

	if (!dest)
		return (NULL);
	if (!src || !nb)
		return (dest);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if	(src_len > nb)
		src_len = nb;
	buffer = malloc(sizeof(char) * (dest_len + src_len + 1));
	ft_strlcpy(buffer, dest, dest_len + 1);
	ft_strlcat(buffer, src, dest_len + src_len + 1);
	free(dest);
	return (buffer);
}

size_t	ft_find_lbreak(char *string)
{
	size_t	i;

	i = 0;
	printf("flag9");
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	printf("flag9.1");
	return (i);
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*string;
	
	if (fd < 0)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	while (*buffer)
	{
		string = ft_strjoin_butcooler(string, buffer, ft_find_lbreak(buffer));
		if (buffer[ft_find_lbreak(buffer)] == '\n' || buffer[ft_find_lbreak(buffer)] == '\0')
			return (string);
		read(fd, buffer, BUFFER_SIZE);
	}
	return (NULL);
}


int	main(void)
{
	int	fd = open("el_quijote.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
