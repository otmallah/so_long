
#include "so_long_bonus.h"

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
                index->cb1 = i;
                index->cb2 = j;
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img3, i, j);
            }
            else if (index->tab[a][b] == 'E')
			{
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img4, i, j);
			}
			else if (index->tab[a][b] == 'K')
			{
				index->xy = i;
				index->yy = j;
				mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
                mlx_put_image_to_window(index->mlx, index->win, index->img11, i, j);				
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

int		number_coin(t_long *index)
{
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	a = 0;
	while(index->tab[j])
	{
		while (index->tab[j][i])
		{
			if (index->tab[j][i] == 'C')
				a++;
			i++;
		}
		i = 0;
		j++;
	}
	return a;
}

int loop_hook(t_long *index)
{
    char *str;
    int r;

	if (index->poss1 == 0 && index->poss2 == 0)
	{
		index->poss1 = find_position_line_K(index->tab1);
		index->poss2 = find_position_index_k(index->tab1);
	}
	r = number_coin(index);
    str = ft_itoa(r);
	mlx_put_image_to_window(index->mlx, index->win, index->img1, 228, 0);
	mlx_string_put(index->mlx, index->win, 240, 30, 0xFFFFFF, str);
    free(str);
	ft_animation_player(index);
	ft_animation_coin(index , 152, 0);
	ft_enemy_animation(index);
	return 0;
}

int     key_hook(int keycode, t_long *index)
{
	if ( index->idx == 0 && index->line == 0)
	{
		index->idx = find_position_index_bonus(index->tab);
		index->line = find_position_line_bonus(index->tab);
	}
	if (index->a != 0 && index->b != 0)
	{
		index->tab[index->a][index->b] = '0';
		index->tab1[index->a][index->b] = '0';
	}
    if (keycode == 124)
		click_right_bonus(index);
    else if (keycode == 123)
		click_left_bonus(index);
    else if (keycode == 126)
		click_up_bonus(index);
    else if (keycode == 125)
		click_down_bonus(index);
	else if (keycode == 53)
		exit(1);
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

int	ft_close(void)
{
	exit(0);
	return 0;
}

int main(int ac, char **av)
{
    t_long index;

    index.fd = open(av[1], O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL || index.str[0] == '\0')
		exit(1);
	index.file = av[1];
	index.tab = key_event_bonus(index.file, &index);
	index.tab1 = key_event_enemy_bonus(index.file, &index);
	ft_window_bonus(av[1]);
	check_size_bonus(av[1]);
	sec_check_bonus(av[1], &index);
	index.mlx = mlx_init();
	index.e = ft_size_width(av[1]);
	index.i = ft_size_height(av[1]);
	index.win = mlx_new_window(index.mlx, index.e, index.i, " lo3ba za3ma hh ");
    index.iimg2 = mlx_xpm_file_to_image(index.mlx, "./test/eats.xpm", &index.x, &index.y);
	index.iimg7 = mlx_xpm_file_to_image(index.mlx, "./test/eats2.xpm", &index.x, &index.y);
    index.iimg8 = mlx_xpm_file_to_image(index.mlx, "./test/eats3.xpm", &index.x, &index.y);
    index.iimg9 = mlx_xpm_file_to_image(index.mlx, "./test/eats4.xpm", &index.x, &index.y);
    index.iimg10 = mlx_xpm_file_to_image(index.mlx, "./test/eats5.xpm", &index.x, &index.y);
    index.img12 = mlx_xpm_file_to_image(index.mlx, "./test/Death.xpm", &index.x, &index.y);
    index.img11 = mlx_xpm_file_to_image(index.mlx, "./test/any.xpm", &index.x, &index.y);
    index.img1 = mlx_xpm_file_to_image(index.mlx, "./test/wall.xpm", &index.x, &index.y);
    index.img2 = mlx_xpm_file_to_image(index.mlx, "./test/eats.xpm", &index.x, &index.y);
    index.img3 = mlx_xpm_file_to_image(index.mlx, "./test/player.xpm", &index.x, &index.y);
    index.img4 = mlx_xpm_file_to_image(index.mlx, "./test/door.xpm", &index.x, &index.y);
    index.img5 = mlx_xpm_file_to_image(index.mlx, "./test/grass.xpm", &index.x, &index.y);
    index.img6 = mlx_xpm_file_to_image(index.mlx, "./test/DOR.xpm", &index.x, &index.y);
    index.img8 = mlx_xpm_file_to_image(index.mlx, "./test/anim1.xpm", &index.x, &index.y);
    index.img9 = mlx_xpm_file_to_image(index.mlx, "./test/anim2.xpm", &index.x, &index.y);
    index.img10 = mlx_xpm_file_to_image(index.mlx, "./test/anim3.xpm", &index.x, &index.y);
    index.img13 = mlx_xpm_file_to_image(index.mlx, "./test/anim4.xpm", &index.x, &index.y);
    index.img14 = mlx_xpm_file_to_image(index.mlx, "./test/anim5.xpm", &index.x, &index.y);
    index.img15 = mlx_xpm_file_to_image(index.mlx, "./test/anim6.xpm", &index.x, &index.y);
    index.img16 = mlx_xpm_file_to_image(index.mlx, "./test/anim7.xpm", &index.x, &index.y);
    index.img17 = mlx_xpm_file_to_image(index.mlx, "./test/anim8.xpm", &index.x, &index.y);
	index.eny = 1;
	check_event(&index);
	mlx_loop_hook(index.mlx, loop_hook, &index);
    mlx_key_hook(index.win, key_hook, &index);
	mlx_hook(index.win, 17, 0, ft_close, &index);
//	system("leaks so_long");
	mlx_loop(index.mlx);
}