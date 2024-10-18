/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   get_next_line.c                                .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.c     |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/10/17 16:12:55 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/10/18 19:33:50 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_butcooler(char *dest, char *src, size_t nb)
{
	char	*buffer;
	size_t	dest_len;
	size_t	src_len;

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
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	return (i);
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*string = NULL;
	
	if (fd < 0)
		return (NULL);
	if (ft_find_lbreak(&buffer[ft_find_lbreak(buffer) + 1]))
		ft_strlcpy(buffer, &buffer[ft_find_lbreak(buffer) + 1], BUFFER_SIZE);
	else
		read(fd, buffer, BUFFER_SIZE);
	while (*buffer)
	{
		string = ft_strjoin_butcooler(string, buffer, ft_find_lbreak(buffer) + 1);
		if (buffer[ft_find_lbreak(buffer)] == '\n')
			return (string);
		read(fd, buffer, BUFFER_SIZE);
	}
	return (NULL);
}


int	main(void)
{
	int	fd = open("el_quijote.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	/*char *dest;
	char src[] = "world";

	dest = malloc(6);
	ft_strlcpy(dest, "Hello ", 7);
	printf("%s", ft_strjoin_butcooler(dest, src, 99));
	*/
}
