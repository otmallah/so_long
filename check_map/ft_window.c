/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:02:06 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/06 22:02:12 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_window(char *file)
{
	t_long	index;

	index.fd = open(file, O_RDONLY);
	index.str = get_next_line(index.fd);
	index.x = 0;
	while (index.str != NULL)
	{
		while (index.str[index.x])
		{
			if (index.str[index.x] != '0' && index.str[index.x] != '1'
				&& index.str[index.x] != 'E' && index.str[index.x] != 'C'
				&&index.str[index.x] != 'P')
			{
				perror(" hh 3afrite ");
				exit(1);
			}
			index.x++;
		}
		index.x = 0;
		free(index.str);
		index.str = get_next_line(index.fd);
	}
	free(index.str);
	close(index.fd);
}
