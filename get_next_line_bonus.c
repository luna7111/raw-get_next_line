/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   get_next_line_bonus.c                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.c     |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/10/17 16:12:55 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/10/29 01:07:54 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strnappend(char *dest, char *src, size_t nb)
{
	char	*buffer;
	size_t	dest_len;
	size_t	src_len;

	if (!src || !nb)
		return (dest);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (src_len > nb)
		src_len = nb;
	buffer = malloc(sizeof(char) * (dest_len + src_len + 1));
	ft_strlcpy(buffer, dest, dest_len + 1);
	ft_strlcat(buffer, src, dest_len + src_len + 1);
	free(dest);
	return (buffer);
}

long	ft_find_lbreak(char *string)
{
	long	i;

	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	return (i);
}

ssize_t	ft_read(int fd, char *buffer, size_t count)
{
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, count);
	buffer[read_bytes] = '\0';
	return (read_bytes);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*string;
	ssize_t		read_bytes;

	string = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_bytes = 1;
	if (buffer[fd][ft_find_lbreak(buffer[fd]) + 1])
		ft_strlcpy(buffer[fd], &buffer[fd][ft_find_lbreak(buffer[fd]) + 1], BUFFER_SIZE);
	else
		read_bytes = ft_read(fd, buffer[fd], BUFFER_SIZE);
	while (read_bytes > 0)
	{
		string = ft_strnappend(string, buffer[fd], ft_find_lbreak(buffer[fd]) + 1);
		if (buffer[fd][ft_find_lbreak(buffer[fd])] == '\n')
			return (string);
		read_bytes = ft_read(fd, buffer[fd], BUFFER_SIZE);
	}
	if (buffer[fd])
		free(buffer[fd]);
	buffer[fd] = NULL;
	return (string);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd2 = open("test1.txt", O_RDONLY);
	fd1 = open("test0.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd2);
	printf("%s", line);
	while (line)
	{
		free(line);
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);

	}
	free(line);
}
