/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:28:25 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/17 13:28:26 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	map_checke_bonus(char *str)
{
	static int	i;
	static int	j;
	static int	k;
	static int	l;
	int			a;

	a = 0;
	while (str[a])
	{
		if (str[a] == 'P')
			i += 2;
		else if (str[a] == 'C')
			j = 2;
		else if (str[a] == 'E')
			k += 2;
		else if (str[a] == 'K')
			l += 2;
		a++;
	}
	if (i == 4 || k == 4 || l == 4)
	{
		write (1, "Please check map\n", 18);
		exit(1);
	}
	return (i + j + k + l);
}

void	complete_map_bonus(t_long *index)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	while (index->tab[i])
	{
		res = map_checke_bonus(index->tab[i]);
		i++;
	}
	if (res != 8)
	{
		write (1, "Please check map\n", 18);
		exit(1);
	}
}
