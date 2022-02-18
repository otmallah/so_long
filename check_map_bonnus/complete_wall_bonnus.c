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

#include "../so_long_bonus.h"

void	check12_bonus(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] != '1')
		{
			write (1, "ERROR1\n", 7);
			exit(1);
		}
		x++;
	}
}

void	sec_check_bonus(char *file, t_long *index)
{
	int		res;
	int		a;
	int		x;
	int		y;
	int		j;

	x = 0;
	y = 0;
	j = 0;
	res = ft_number_line_bonus(file);
	a = res;
	while (res > 0)
	{
		if (res == 1 || res == a)
			check12_bonus(index->tab[x]);
		j = ft_strlen(index->tab[x]) - 1;
		if (index->tab[x][0] == '1' && index->tab[x][j] == '1')
			x++;
		else
		{
			write (1, "ERROR2\n", 7);
			exit(1);
		}
		res--;
	}
}
