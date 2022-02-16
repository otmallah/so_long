/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_bonnus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:32:35 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 17:32:36 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	**key_event_bonus(char *file, t_long *index)
{
	int		i;
	int		x;
	char	*str;
	int		a;
	char	**str2;

	i = 0;
	index->fd = open(file, O_RDONLY);
	str = get_next_line(index->fd);
	a = ft_number_line_bonus(index->file);
	str2 = calloc(sizeof(char *), (a + 1));
	while (str)
	{
		x = strlen(str);
		str2[i] = calloc(sizeof(char), (x + 1));
		i++;
		free(str);
		str = get_next_line(index->fd);
	}
	ft_wall_bonus(str2, index);
	return (str2);
}

char	**key_event_enemy_bonus(char *file, t_long *index)
{
	int		i;
	int		x;
	char	*str;
	int		a;
	char	**str2;

	i = 0;
	index->fd = open(file, O_RDONLY);
	str = get_next_line(index->fd);
	a = ft_number_line_bonus(index->file);
	str2 = calloc(sizeof(char *), (a + 1));
	while (str)
	{
		x = strlen(str);
		str2[i] = calloc(sizeof(char), (x + 1));
		i++;
		free(str);
		str = get_next_line(index->fd);
	}
	ft_wall_bonus(str2, index);
	return (str2);
}
