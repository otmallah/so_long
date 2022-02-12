
#include "../so_long.h"

int		find_position_index_k(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'K')
				return i;
			i++;
		}
		i = 0;
		j++;
	}
	return 0;
}

int		find_position_line_K(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'K')
				return j;
			i++;
		}
		i = 0;
		j++;
	}
	return 0;
}