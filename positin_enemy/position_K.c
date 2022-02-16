/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_K.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:21:49 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 23:21:50 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	find_position_index_k(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'K')
				return (i);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	find_position_line_k(char	**tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'K')
				return (j);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
