#include "../so_long.h"

int		find_position_index(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'P')
				return i;
			i++;
		}
		i = 0;
		j++;
	}
	return 0;
}

int		find_position_line(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'P')
				return j;
			i++;
		}
		i = 0;
		j++;
	}
	return 0;
}

void	ft_wall(char **tab, t_long *index)
{
	int		fd = open(index->file , O_RDONLY);
	char	*str;
	int		i = 0;
	int		j = 0;
	int		a = 0;

	str = get_next_line(fd);
	while (str != NULL)
	{
		while(str[i])
		{
			tab[j][a] = str[i];
			i++;
			a++;
		}
		i = 0;
		a = 0;
		j++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	tab[j] = NULL;
	close(fd);
}
