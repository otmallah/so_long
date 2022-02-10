/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:22:29 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/06 22:22:33 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

int		ft_size_height(char *file)
{
	t_long index;

	index.fd = open(file, O_RDONLY);
	index.str = get_next_line(index.fd);
	index.e = 0;
	while (index.str != NULL)
	{
		index.e = index.e + 75;
		free(index.str);
		index.str = get_next_line(index.fd);
	}
	return index.e;
}
