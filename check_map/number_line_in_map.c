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

int	ft_number_line(void)
{
	char	*test;
	int 	i;

	i = 0;
	int fd = open("test/test.ber" , O_RDONLY);
	test = get_next_line(fd);
	while (test != NULL)
	{
		test = get_next_line(fd);
		i++;
	}
	return i;
}
