/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:24:20 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/06 22:24:21 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

int		ft_size_width(void)
{
	t_long index;

	index.fd = open("./test/test.ber" , O_RDONLY);
	index.str = get_next_line(index.fd);
	index.x = 0;
	index.a = 0;
	while (index.str[index.x])
	{
		index.a = index.a + 76;
		index.x++;
	}
	return index.a;
}