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
		index->tab = key_event(index->file, index);
	if (index->a != 0 && index->b != 0)
		index->tab[index->a][index->b] = '0';
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
	a++;
    return 0;
}

void	mouvement(t_long *index, char *file)
{
	int x = 76;
	int y = 76;
	while (x <= 156)
	{
		mlx_clear_window(index->mlx, index->win);
		check_event(index, file);
    	mlx_put_image_to_window(index->mlx, index->win, index->img2, x, y);
		x += 10;
		mlx_clear_window(index->mlx, index->win);
		check_event(index, file);
    	mlx_put_image_to_window(index->mlx, index->win, index->img7, x, y);
		x += 10;
		mlx_clear_window(index->mlx, index->win);
		check_event(index, file);
    	mlx_put_image_to_window(index->mlx, index->win, index->img8, x, y);
		x += 10;
		mlx_clear_window(index->mlx, index->win);
		check_event(index, file);
    	mlx_put_image_to_window(index->mlx, index->win, index->img9, x, y);
		x += 10;
		mlx_clear_window(index->mlx, index->win);
		check_event(index, file);
    	mlx_put_image_to_window(index->mlx, index->win, index->img10, x, y);
	}
	x = 76;
	y = 76;
}

int x = 76;
int y = 76;

int loop_hook(t_long *index)
{
	if (x == 80)
		x = 76;
    mlx_put_image_to_window(index->mlx, index->win, index->img2, x, y);
    mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
    mlx_put_image_to_window(index->mlx, index->win, index->img7, x, y);
    mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
    mlx_put_image_to_window(index->mlx, index->win, index->img8, x, y);
	mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
    mlx_put_image_to_window(index->mlx, index->win, index->img9, x, y);
	mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
    mlx_put_image_to_window(index->mlx, index->win, index->img10, x, y);
	x++;
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
    index.img9 = mlx_xpm_file_to_image(index.mlx, "./test/eats4.xpm", &index.x, &index.y);
    index.img10 = mlx_xpm_file_to_image(index.mlx, "./test/eats5.xpm", &index.x, &index.y);
    check_event(&index, av[1]);
    mlx_key_hook(index.win, key_hook, &index);
	mlx_loop_hook(index.mlx, loop_hook, &index);
	mlx_loop(index.mlx);
}
