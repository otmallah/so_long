#include "so_long.h"

void    check_event(t_long *index)
{
    int i, j, a, fd;
    char *str;

    fd = open("./test/test.ber", O_RDONLY);
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


void    check_event2(t_long *index)
{
    int i;
    int j;
    int e;
    int k;
    int l = 0;

    i = 0;
    j = 0;
    e = 0;
    k = 0;

	if (index->str2[0] == 0)
	{
		index->str2 = key_event();
		while (index->str2[j] != NULL)
		{
			while (index->str2[j][i])
			{
				if (index->str2[j][i] == '1')
					mlx_put_image_to_window(index->mlx, index->win, index->img1, e, k);
				else if (index->str2[j][i] == '0' || index->str2[j][i] == 'P')
					mlx_put_image_to_window(index->mlx, index->win, index->img5, e, k);
				else if (index->str2[j][i] == 'E')
				{
					mlx_put_image_to_window(index->mlx, index->win, index->img5, e, k);
					mlx_put_image_to_window(index->mlx, index->win, index->img4, e, k);
				}
				else if (index->str2[j][i] == 'C')
				{
					mlx_put_image_to_window(index->mlx, index->win, index->img5, e, k);
					mlx_put_image_to_window(index->mlx, index->win, index->img2, e, k);
				}
				i++;
				e += 76;
			}
			i = 0;
			j++;
			e = 0;
			k += 76;
		}
	}
	else
	{
		if (a != 0 && b != 0)
			index->str2[a][b] = '0';
		while (index->str2[j] != NULL)
		{
			while (index->str2[j][i])
			{
				if (index->str2[j][i] == '1')
					mlx_put_image_to_window(index->mlx, index->win, index->img1, e, k);
				else if (index->str2[j][i] == '0' || index->str2[j][i] == 'P')
					mlx_put_image_to_window(index->mlx, index->win, index->img5, e, k);
				else if (index->str2[j][i] == 'E')
				{
					mlx_put_image_to_window(index->mlx, index->win, index->img5, e, k);
					mlx_put_image_to_window(index->mlx, index->win, index->img4, e, k);
				}
				else if (index->str2[j][i] == 'C')
				{
					mlx_put_image_to_window(index->mlx, index->win, index->img5, e, k);
					mlx_put_image_to_window(index->mlx, index->win, index->img2, e, k);
				}
				i++;
				e += 76;
			}
			i = 0;
			j++;
			e = 0;
			k += 76;
		}
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

void	ft_animation(t_long *index)
{
	m = count1;
	n = count2;

    mlx_put_image_to_window(index->mlx, index->win, index->img5, m, n);
    mlx_put_image_to_window(index->mlx, index->win, index->img7, m, n);
	m += 20;
    mlx_put_image_to_window(index->mlx, index->win, index->img5, m, n);
    mlx_put_image_to_window(index->mlx, index->win, index->img8, m, n);
	m += 20;
    mlx_put_image_to_window(index->mlx, index->win, index->img5, m, n);
	mlx_put_image_to_window(index->mlx, index->win, index->img9, m, n);
	m += 20;
    mlx_put_image_to_window(index->mlx, index->win, index->img5, m, n);
	mlx_put_image_to_window(index->mlx, index->win, index->img10, m, n);
	m += 20;

}

int     key_hook(int keycode, t_long *index)
{
    index->tab = key_event();
    if (keycode == 124)
    {
		if (index->tab[line][idx + 1] == 'E')
		{
			index->a = ft_exit(index->str2);
			if (index->a == 0)
			{
				mlx_put_image_to_window(index->mlx, index->win, index->img5, f, p);
				mlx_put_image_to_window(index->mlx, index->win, index->img6, f, p);
				free(index->str2);
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
           // mlx_clear_window(index->mlx, index->win);
		  //
		   ft_animation(index);
            check_event2(index);
            count1 += 76;
            mlx_put_image_to_window(index->mlx, index->win, index->img3, count1, count2);
        }
    }
    else if (keycode == 123)
    {
		if (index->tab[line][idx- 1] == 'E')
		{
			index->a = ft_exit(index->str2);
			if (index->a == 0)
			{
				mlx_put_image_to_window(index->mlx, index->win, index->img5, f, p);
				mlx_put_image_to_window(index->mlx, index->win, index->img6, f, p);
				free(index->str2);
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
            printf("%d %d\n" , count1 , count2);
            check_event2(index);
            count1 -= 76;
            mlx_put_image_to_window(index->mlx, index->win, index->img3, count1, count2);
        }
    }
    else if (keycode == 126)
    {
		if (index->tab[line - 1][idx] == 'E')
		{
			index->a = ft_exit(index->str2);
			if (index->a == 0)
			{
				mlx_put_image_to_window(index->mlx, index->win, index->img5, f, p);
				mlx_put_image_to_window(index->mlx, index->win, index->img6, f, p);
				free(index->str2);
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
            printf("%d %d\n" , count1 , count2);
            check_event2(index);
            count2 -= 76;
            mlx_put_image_to_window(index->mlx, index->win, index->img3, count1, count2);
        }
    }
    else if (keycode == 125)
    {

		if (index->tab[line + 1][idx] == 'E')
		{
			index->a = ft_exit(index->str2);
			if (index->a == 0)
			{
				mlx_put_image_to_window(index->mlx, index->win, index->img5, f, p);
				mlx_put_image_to_window(index->mlx, index->win, index->img6, f, p);
				free(index->str2);
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
            printf("%d %d\n" , count1 , count2);
            check_event2(index);
            count2 += 76;
            mlx_put_image_to_window(index->mlx, index->win, index->img3, count1, count2);
        }
    }
    return 0;
}

int main(void)
{
	t_long 	index;

    index.path1 = "./test/wall.xpm";
    index.path2 = "./test/eats.xpm";
    index.path3 = "./test/player.xpm";
    index.path4 = "./test/bab.xpm";
	index.path5 = "./test/ok.xpm.xpm";
	index.path6 = "./test/DOR.xpm";
	index.path7 = "./test/run1.xpm";
	index.path8 = "./test/run2.xpm";
	index.path9 = "./test/run3.xpm";
	index.path10 = "./test/run4.xpm";
    index.fd = open("./test/test.ber", O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL)
	{
		//puts("im here");
		printf("%s\n" , strerror(errno));
		exit(1);
	}
	//ft_complete_map();
	ft_window();
	check_size();
	sec_check();
	index.mlx = mlx_init();
	index.a = ft_size_width();
	index.i = ft_size_height();
	index.win = mlx_new_window(index.mlx, index.a, index.i, " lo3ba za3ma ");
    index.img1 = mlx_xpm_file_to_image(index.mlx, index.path1, &index.x, &index.y);
    index.img2 = mlx_xpm_file_to_image(index.mlx, index.path2, &index.x, &index.y);
    index.img3 = mlx_xpm_file_to_image(index.mlx, index.path3, &index.x, &index.y);
    index.img4 = mlx_xpm_file_to_image(index.mlx, index.path4, &index.x, &index.y);
    index.img5 = mlx_xpm_file_to_image(index.mlx, index.path5, &index.x, &index.y);
    index.img6 = mlx_xpm_file_to_image(index.mlx, index.path6, &index.x, &index.y);
    index.img7 = mlx_xpm_file_to_image(index.mlx, index.path7, &index.x, &index.y);
    index.img8 = mlx_xpm_file_to_image(index.mlx, index.path8, &index.x, &index.y);
    index.img9 = mlx_xpm_file_to_image(index.mlx, index.path9, &index.x, &index.y);
    index.img10 = mlx_xpm_file_to_image(index.mlx, index.path10, &index.x, &index.y);
    check_event(&index);
    mlx_key_hook(index.win, key_hook, &index);
	system("leaks a.out");
	mlx_loop(index.mlx);
}
