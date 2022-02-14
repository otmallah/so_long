#include "so_long.h"

void    check_event(t_long *index, char *file)
{
    int i, j, a, fd;
    char *str;

    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    while (str != NULL)
    {
        while (str[a])
        {
            if (str[a] == '1')
                mlx_put_image_to_window(index->mlx, index->win, index->img1, i, j);
            else if (str[a] == '0')
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
            else if (str[a] == 'C')
			{
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img2 , i, j);
			}
            else if (str[a] == 'P')
            {
                index->count1 = i;
                index->count2 = j;
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img3, i, j);
            }
            else if (str[a] == 'E')
			{
				f = i;
				p = j;
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img4, i, j);
			}
			else if (str[a] == 'K')
			{
				xeny = i;
				yeny = j;
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img11, i, j);				
			}
            a++;
            i +=76;
        }
        a = 0;
        i = 0;
        j += 76;
		free(str);
        str = get_next_line(fd);
    }
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
	if (index->a == 0)
	{
		index->tab = key_event(index->file, index);
		index->tab1 = key_event_enemy(index->file, index);
	}
	if (index->pos1 == 0 && index->pos2 == 0)
	{
		index->pos1 = find_position_line_K(index->tab1);
		index->pos2 = find_position_index_k(index->tab1);
	}
	printf("line = %d , index = %d \n", index->pos1, index->pos2);
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

int main(int ac, char **av)
{
	t_long 	index;

    index.fd = open(av[1], O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL || index.str[0] == '\0')
		exit(1);
	index.file = av[1];
	ft_complete_map(av[1], &index);
	ft_window(av[1]);
	check_size(av[1]);
	sec_check(av[1]);
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
    index.img7 = mlx_xpm_file_to_image(index.mlx, "./test/eats2.xpm", &index.x, &index.y);
    index.img8 = mlx_xpm_file_to_image(index.mlx, "./test/eats3.xpm", &index.x, &index.y);
    index.img9 = mlx_xpm_file_to_image(index.mlx, "./test/DEATH2.xpm", &index.x, &index.y);
    index.img10 = mlx_xpm_file_to_image(index.mlx, "./test/Death.xpm", &index.x, &index.y);
    index.img11 = mlx_xpm_file_to_image(index.mlx, "./test/any.xpm", &index.x, &index.y);
	index.eny = 1;
	check_event(&index, av[1]);
    mlx_key_hook(index.win, key_hook, &index);
	mlx_loop(index.mlx);
}
