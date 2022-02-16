#include "so_long.h"


int    check_event(t_long *index)
{
    int i, j, a, b;
    while (index->tab[a] != NULL)
    {
        while (index->tab[a][b])
        {
            if (index->tab[a][b] == '1')
                mlx_put_image_to_window(index->mlx, index->win, index->img1, i, j);
            else if (index->tab[a][b] == '0')
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
            else if (index->tab[a][b] == 'C')
			{
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img2, i, j);
			}
            else if (index->tab[a][b] == 'P')
            {
                index->count1 = i;
                index->count2 = j;
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img3, i, j);
            }
            else if (index->tab[a][b] == 'E')
			{
				f = i;
				p = j;
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img4, i, j);
			}
            b++;
            i +=76;
        }
		b = 0;
        a++;
        i = 0;
        j += 76;
    }
	return 0;
}

int	ft_exit(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(tab[j] != NULL)
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'C')
				return 1;
			i++;
		}
		i = 0;
		j++;
	}
	return 0;
}

int     key_hook(int keycode, t_long *index)
{
	if ( index->idx == 0 && index->line == 0)
	{
		index->idx = find_position_index(index->tab);
		index->line = find_position_line(index->tab);
	}
	if (index->a != 0 && index->b != 0)
	{
		index->tab[index->a][index->b] = '0';
		index->tab1[index->a][index->b] = '0';
	}
    if (keycode == 124)
		click_right(index);
    else if (keycode == 123)
		click_left(index);
    else if (keycode == 126)
		click_up(index);
    else if (keycode == 125)
		click_down(index);
	else if (keycode == 53)
		exit(1);
    return 0;
}

int	ft_close(void)
{
	exit(0);
	return 0;
}

int main(int ac, char **av)
{
	t_long 	index;

    index.fd = open(av[1], O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL || index.str[0] == '\0')
		exit(1);
	index.file = av[1];
	index.tab = key_event(index.file, &index);
	index.tab1 = key_event_enemy(index.file, &index);
	ft_complete_map(av[1], &index);
	ft_window(av[1]);
	check_size(av[1]);
	sec_check(av[1], &index);
	index.mlx = mlx_init();
	index.e = ft_size_width(av[1]);
	index.i = ft_size_height(av[1]);
	index.win = mlx_new_window(index.mlx, index.e, index.i, " lo3ba za3ma ");
    index.img1 = mlx_xpm_file_to_image(index.mlx, "./test/wall.xpm", &index.x, &index.y);
    index.img2 = mlx_xpm_file_to_image(index.mlx, "./test/eats.xpm", &index.x, &index.y);
    index.img3 = mlx_xpm_file_to_image(index.mlx, "./test/player.xpm", &index.x, &index.y);
    index.img4 = mlx_xpm_file_to_image(index.mlx, "./test/door.xpm", &index.x, &index.y);
    index.img5 = mlx_xpm_file_to_image(index.mlx, "./test/grass.xpm", &index.x, &index.y);
    index.img6 = mlx_xpm_file_to_image(index.mlx, "./test/DOR.xpm", &index.x, &index.y);
	check_event(&index);
    mlx_key_hook(index.win, key_hook, &index);
	mlx_hook(index.win, 17, 0, ft_close, &index);
	system("leaks so_long");
	mlx_loop(index.mlx);
}