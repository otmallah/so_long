/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:58:35 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 23:58:38 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_checker(char *str)
{
	static int	i;
	static int	j;
	static int	k;
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
		a++;
	}
	if (i == 4 || k == 4)
	{
		write (1, "Please check map\n", 18);
		exit(1);
	}
	return (i + j + k);
}

void	complete_map(t_long *index)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	while (index->tab[i])
	{
		res = map_checker(index->tab[i]);
		i++;
	}
	if (res != 6)
	{
		write (1, "Please check map\n", 18);
		exit(1);
	}
}
