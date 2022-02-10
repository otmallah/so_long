#include "so_long.h"

void    check_event(t_long *index, char *file)
{
    int i, j, a, fd;
    char *str;

	puts("is");
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
                count1 = i;
                count2 = j;
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

void	click_right(t_long *index)
{
	if (index->tab[line][idx + 1] == 'E')
	{
		index->a = ft_exit(index->tab);
		if (index->a == 0)
		{
			free(index->tab);
			exit(1);
		}
		else
			index->a = index->a;
	}
    if (index->tab[line][idx + 1] != '1' && index->tab[line][idx + 1] != 'E')
    {
        idx++;
        if (index->tab[line][idx] == 'C')
        {
            a = line;
            b = idx;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, count1, count2);
        count1 += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, count1, count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, count1, count2);
    }
}

void	click_left(t_long *index)
{
	if (index->tab[line][idx- 1] == 'E')
		{
			index->a = ft_exit(index->tab);
			if (index->a == 0)
			{
				free(index->tab);
				exit(1);
			}
			else
				index->a = index->a;
		}
        if (index->tab[line][idx - 1] != '1' && index->tab[line][idx - 1] != 'E')
        {
            idx--;
            if (index->tab[line][idx] == 'C')
            {
                a = line;
                b = idx;
            }
			mlx_put_image_to_window(index->mlx, index->win, index->img5, count1, count2);
            count1 -= 76;
			mlx_put_image_to_window(index->mlx, index->win, index->img5, count1, count2);
            mlx_put_image_to_window(index->mlx, index->win, index->img3, count1, count2);
        }
}

void	click_up(t_long *index)
{
	if (index->tab[line - 1][idx] == 'E')
	{
		index->a = ft_exit(index->tab);
		if (index->a == 0)
		{
			free(index->tab);
			exit(1);
		}
		else
		index->a = index->a;
	}	
    if (index->tab[line - 1][idx] != '1' && index->tab[line - 1][idx] != 'E')
    {
    	line--;
        if (index->tab[line][idx] == 'C')
        {
            a = line;
            b = idx;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, count1, count2);
        count2 -= 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, count1, count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, count1, count2);
    }
}

void	click_down(t_long *index)
{
	if (index->tab[line + 1][idx] == 'E')
	{
		index->a = ft_exit(index->tab);
		if (index->a == 0)
		{
			free(index->tab);
			exit(1);
		}
		else
		index->a = index->a;
	}
    if (index->tab[line + 1][idx] != '1' && index->tab[line + 1][idx] != 'E')
    {
        line++;
        if (index->tab[line][idx] == 'C')
        {
            a = line;
            b = idx;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, count1, count2);
	    count2 += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, count1, count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, count1, count2);
   }
}

int     key_hook(int keycode, t_long *index)
{
	if (a == 0)
   		index->tab = key_event(index->file, index);
	if (a != 0 && b != 0)
		index->tab[a][b] = '0';
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
	printf("%s \n" , av[1]);
	if (index.str == NULL)
	{
		printf("%s\n" , strerror(errno));
		exit(1);
	}
	index.file = av[1];
	ft_window(av[1]);
	check_size(av[1]);
	sec_check(av[1]);
	index.mlx = mlx_init();
	index.a = ft_size_width(av[1]);
	index.i = ft_size_height(av[1]);
	index.win = mlx_new_window(index.mlx, index.a, index.i, " lo3ba za3ma ");
    index.img1 = mlx_xpm_file_to_image(index.mlx, "./test/wall.xpm", &index.x, &index.y);
    index.img2 = mlx_xpm_file_to_image(index.mlx, "./test/eats.xpm", &index.x, &index.y);
    index.img3 = mlx_xpm_file_to_image(index.mlx, "./test/player.xpm", &index.x, &index.y);
    index.img4 = mlx_xpm_file_to_image(index.mlx, "./test/bab.xpm", &index.x, &index.y);
    index.img5 = mlx_xpm_file_to_image(index.mlx, "./test/ok.xpm.xpm", &index.x, &index.y);
    index.img6 = mlx_xpm_file_to_image(index.mlx, "./test/DOR.xpm", &index.x, &index.y);
    check_event(&index, av[1]);
    mlx_key_hook(index.win, key_hook, &index);
	mlx_loop(index.mlx);
}
