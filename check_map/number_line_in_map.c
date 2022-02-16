/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_line_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:14:06 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/06 22:14:07 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_number_line(char *file)
{
	char	*test;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	test = get_next_line(fd);
	while (test != NULL)
	{
		i++;
		free(test);
		test = get_next_line(fd);
	}
	close(fd);
	free(test);
	return (i);
}
