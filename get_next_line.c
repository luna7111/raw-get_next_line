/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldel-val <ldel-val@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:06 by ldel-val          #+#    #+#             */
/*   Updated: 2024/10/14 20:33:39 by ldel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	ft_find_linebreak(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i ++;
	}
	return (-1);
}

void	ft_trim_before_break(char *string)
{
	size_t i;

	if (!ft_find_linebreak)
		return ;
	i = 0;
}

char *get_next_line(fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*string
	size_t		current_position

	current_position = 0;
	if (ft_find_linebreak(buffer) < 0)
		ft_trim_before_break(buffer);
}

/*
int	main(void)
{
	printf("%ld\n", ft_find_linebreak("ajaahahahahha"));
}*/
