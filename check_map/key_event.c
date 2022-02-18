/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:05:42 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 21:05:44 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**key_event(char *file, t_long *index)
{
	int		i;
	int		x;
	char	*str;
	int		a;
	char	**str2;

	i = 0;
	index->fd = open(file, O_RDONLY);
	str = get_next_line(index->fd);
	a = ft_number_line(index->file);
	str2 = ft_calloc(sizeof(char *), (a + 1));
	while (str)
	{
		x = ft_strlen(str);
		str2[i] = ft_calloc(sizeof(char), (x + 1));
		i++;
		free(str);
		str = get_next_line(index->fd);
	}
	ft_wall(str2, index);
	free(str);
	return (str2);
}

char	**key_event_enemy(char *file, t_long *index)
{
	int		i;
	int		x;
	char	*str;
	int		a;
	char	**str2;

	i = 0;
	index->fd = open(file, O_RDONLY);
	str = get_next_line(index->fd);
	a = ft_number_line(index->file);
	str2 = ft_calloc(sizeof(char *), (a + 1));
	while (str)
	{
		x = ft_strlen(str);
		str2[i] = ft_calloc(sizeof(char), (x + 1));
		i++;
		free(str);
		str = get_next_line(index->fd);
	}
	ft_wall(str2, index);
	free(str);
	return (str2);
}
