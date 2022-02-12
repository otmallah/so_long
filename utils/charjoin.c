/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:22:44 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/12 14:22:45 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

size_t  ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

static char	*ft_strcat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		i++;
	}
	while (str2[j])
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[i + j] = '\0';
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		k;
	int		i;
	int		j;

	k = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	str = (char *)malloc(i + j +1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	if (!str)
		return (NULL);
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	return (str);
}

int main(void)
{
	int a = 15;
	char *c = ft_itoa(a);
	char *str = ft_strjoin(strdup("ana"), c);
	printf("%s \n", str);
}