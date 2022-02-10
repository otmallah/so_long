/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:03:37 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/06 22:03:38 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

void	sec_check(char *file)
{
	t_long	index;
	int		res;
	int		a;

	index.fd = open(file , O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL)
		exit(1);
	index.x = 0;
	res = ft_number_line(file);
	a = res;
	while (res > 0)
	{
		if (res == 1 || res == a)
		{
			while (index.str[index.x])
			{
				if (index.str[index.x] != '1')
				{
					puts("ERROR1");
					exit(1);
				}
				index.x++;
			}
			index.x = 0;
		}
		index.y = strlen(index.str) - 1;
		if (index.str[0] == '1' && index.str[index.y] == '1')
		{
			free(index.str);
			index.str = get_next_line(index.fd);
		}
		else
		{
			puts("ERROR2");
			exit(1);			
		}
		res--;
	}
	free(index.str);
	close(index.fd);
}
