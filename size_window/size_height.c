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

int		ft_size_height(void)
{
	t_long index;

	index.fd = open("./test/test.ber", O_RDONLY);
	index.str = get_next_line(index.fd);
	index.a = 0;
	while (index.str != NULL)
	{
		index.a = index.a + 75;
		index.str = get_next_line(index.fd);
	}
	return index.a;
}
