/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:00:43 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/06 22:00:45 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_size_bonus2(int y, int x, int e)
{
	if (y == x && e < y)
		y++;
	else
	{
		perror("The map must be rectangular.");
		exit(1);
	}
}

void	check_size_bonus(char *file)
{
	t_long	index;

	index.e = 0;
	index.fd = open(file, O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL)
		exit(1);
	index.x = strlen(index.str);
	while (index.str != NULL)
	{
		index.y = strlen(index.str);
		if (index.y != index.x)
		{
			perror("error");
			exit(1);
		}
		free(index.str);
		index.str = get_next_line(index.fd);
		index.e++;
	}
	if (index.str == NULL)
		check_size_bonus2(index.y, index.x, index.e);
	free(index.str);
}
