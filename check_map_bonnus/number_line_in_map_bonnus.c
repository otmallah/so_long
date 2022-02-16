/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_line_in_map_bonnus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:34:06 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 17:34:08 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_number_line_bonus(char *file)
{
	char	*test;
	int 	i;

	i = 0;
	int fd = open(file , O_RDONLY);
	test = get_next_line(fd);
	while (test != NULL)
	{
		i++;
		free(test);
		test = get_next_line(fd);
	}
	close(fd);
	return i;
}
