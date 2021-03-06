/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:35:06 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 17:35:07 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	find_position_index_bonus(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'P')
				return (i);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	find_position_line_bonus(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'P')
				return (j);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

void	ft_wall_bonus(char **tab, t_long *index)
{
	int		i;
	int		j;
	int		a;

	i = 0;
	j = 0;
	a = 0;
	index->fd = open(index->file, O_RDONLY);
	index->str = get_next_line(index->fd);
	while (index->str != NULL)
	{
		while (index->str[i])
		{
			tab[j][a] = index->str[i];
			i++;
			a++;
		}
		i = 0;
		a = 0;
		j++;
		free(index->str);
		index->str = get_next_line(index->fd);
	}
	tab[j] = NULL;
	free(index->str);
}
