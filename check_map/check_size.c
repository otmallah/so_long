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

#include "../so_long.h"

int    check_size(char *file)
{
	t_long index;

	index.a = 0;
	index.fd = open(file , O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL)
		return (0);
	index.x = strlen(index.str);
	while(index.str != NULL) 
	{
		index.y = strlen(index.str);
		if (index.y != index.x)
		{
			perror("error");
			exit(1);
		}
		free(index.str);
		index.str = get_next_line(index.fd);
		index.a++;
	}
	if (index.str == NULL)
	{
		if (index.y == index.x && index.a < index.y)
			index.y++;
		else
		{
			perror("The map must be rectangular.");
			exit(1);
		}
	}
	free(index.str);
	close(index.fd);
	return 0;
}
