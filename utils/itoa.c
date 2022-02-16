/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:16:03 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/12 14:16:04 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t n, size_t c)
{
	void	*str;
	size_t	i;

	i = 0;
	str = malloc(n * c);
	if (str == 0)
		return (NULL);
	while (i < (n * c))
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}

static char	convert(int n, char *c, int i)
{
	long int	g;

	g = n;
	if (n == 0)
		c[0] = 48;
	if (n < 0)
	{
		c[0] = '-';
		g *= -1;
	}
	while (i >= 0 && g > 0)
	{
		c[i] = g % 10 + 48;
		g /= 10 ;
		i--;
	}
	return (*c);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		i;
	int		t;

	t = n;
	i = 0;
	if (t < 0)
	{
		t *= -1;
		i++;
	}
	if (t == 0)
		i = 1;
	while (t != 0)
	{
		t /= 10;
		i++;
	}
	string = (char *)ft_calloc(sizeof(char), i + 1);
	if (!string)
		return (NULL);
	i--;
	convert(n, string, i);
	return (string);
}
