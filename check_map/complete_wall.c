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

void	check12(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (str[x] != '1')
		{
			puts("ERROR1");
			exit(1);
		}
		x++;
	}
}

void	sec_check(char *file, t_long *index)
{
	int		res;
	int		a;
	int x = 0;
	int y = 0;
	int j = 0;
	res = ft_number_line(file);
	a = res;
	while (res > 0)
	{
		if (res == 1 || res == a)
			check12(index->tab[x]);
		j = strlen(index->tab[x]) - 1;
		if (index->tab[x][0] == '1' && index->tab[x][j] == '1')
			x++;
		else
		{
			puts("ERROR2");
			exit(1);			
		}
		res--;
	}
}
