/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldel-val <ldel-val@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:06 by ldel-val          #+#    #+#             */
/*   Updated: 2024/10/14 19:43:13 by ldel-val         ###   ########.fr       */
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
/*
int	main(void)
{
	printf("%ld\n", ft_find_linebreak("ajaahahahahha"));
}*/
