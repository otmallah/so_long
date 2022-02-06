#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "get/get_next_line.h"

typedef struct	s_long {
	void	*mlx;
	void	*win;
    void    *path1;
    void    *path2;
    void    *path3;
    void    *path4;
    void    *img1;
    void    *img2;
    void    *img3;
    void    *img4;
    int     x, y,  i,a,fd;
    char    *str;
    char    **str2;
	char	**tab;
}	t_long;

int count1;
int count2;
int idx;
int line;
int a;
int b;

int	salam(void)
{
	char	*test;
	int 	i;

	i = 0;
	int fd = open("test/test.ber" , O_RDONLY);
	test = get_next_line(fd);
	while (test != NULL)
	{
		test = get_next_line(fd);
		i++;
	}
	return i;
}

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
                a = a;
            else if (str[a] == 'C')
                mlx_put_image_to_window(index->mlx, index->win, index->img2 , i, j);
            else if (str[a] == 'P')
            {
                count1 = i;
                count2 = j;
                mlx_put_image_to_window(index->mlx, index->win, index->img3, i, j);
            }
            else if (str[a] == 'E')
                mlx_put_image_to_window(index->mlx, index->win, index->img4, i, j);
            a++;
            i +=76;
        }
        a = 0;
        i = 0;
        j += 76;
        str = get_next_line(fd);
    }
}

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

void	ft_wall(char **tab)
{
	int		fd = open("./test/test.ber" , O_RDONLY);
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
		str = get_next_line(fd);
	}
	tab[j] = NULL;
}

char   **key_event(void)
{
    int i = 0;
	int x;
    int  fd = open("./test/test.ber" , O_RDONLY);
    char *str = get_next_line(fd);
    int a = salam();
    char **str2 = calloc(sizeof(char *) , (a + 1));
    while (str)
    {
        x = strlen(str);
        str2[i] = calloc(sizeof(char) , (x + 1));
        i++;
        str = get_next_line(fd);
    }
    ft_wall(str2);
    if ( idx == 0 && line == 0)
	{
		idx = find_position_index(str2);
		line = find_position_line(str2);
	}
	return str2;
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
				else if (index->str2[j][i] == '0')
					i = i;
				else if (index->str2[j][i] == 'E')
					mlx_put_image_to_window(index->mlx, index->win, index->img4, e, k);
				else if (index->str2[j][i] == 'C')
					mlx_put_image_to_window(index->mlx, index->win, index->img2, e, k);
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
				else if (index->str2[j][i] == '0')
					i = i;
				else if (index->str2[j][i] == 'E')
					mlx_put_image_to_window(index->mlx, index->win, index->img4, e, k);
				else if (index->str2[j][i] == 'C')
					mlx_put_image_to_window(index->mlx, index->win, index->img2, e, k);
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
            mlx_clear_window(index->mlx, index->win);
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
            mlx_clear_window(index->mlx, index->win);
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
            mlx_clear_window(index->mlx, index->win);
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
            mlx_clear_window(index->mlx, index->win);
            check_event2(index);
            count2 += 76;
            mlx_put_image_to_window(index->mlx, index->win, index->img3, count1, count2);
        }
    }
    return 0;
}

int		ft_size_window(void)
{
	t_long index;

	index.fd = open("./test/test.ber" , O_RDONLY);
	index.str = get_next_line(index.fd);
	index.x = 0;
	index.a = 0;
	while (index.str[index.x])
	{
		index.a = index.a + 76;
		index.x++;
	}
	return index.a;
}

int		ft_size_window2(void)
{
	t_long index;

	index.fd = open("./test/test.ber", O_RDONLY);
	index.str = get_next_line(index.fd);
	index.a = 0;
	while (index.str != NULL)
	{
		index.a = index.a + 75;
		index.str = get_next_line(index.fd);
	}
	return index.a;
}

void	sec_check(void)
{
	t_long	index;
	int res;
	int a;

	index.fd = open("test/test.ber" , O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL)
		exit(1);
	index.x = 0;
	res = salam();
	//printf("%d\n" , res);
	a = res;
	while (res > 0)
	{
		if (res == 1 || res == a)
		{
			while (index.str[index.x])
			{
				if (index.str[index.x] != '1')
				{
					puts("ERROR1");
					exit(1);
				}
				index.x++;
			}
			index.x = 0;
		}
		index.y = strlen(index.str) - 1;
		if (index.str[0] == '1' && index.str[index.y] == '1')
			index.str = get_next_line(index.fd);
		else
		{
			puts("ERROR2");
			exit(1);			
		}
		res--;
		//printf("%s \n" , index.str);
	}
}

int    check_size(void)
{
	int k = 0, l = 0;
	int fd;
	int i;
	int cout;
	char *str;
	cout = 0;

	//sec_check();
	fd = open("test/test.ber" , O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (0);
	k = strlen(str);
	while(str != NULL) 
	{
		l = strlen(str);
		if (l != k)
		{
			perror("error");
			exit(1);
		}
		str = get_next_line(fd);
		cout++;
	}
	if (str == NULL)
	{
		if (l == k && cout < l)
			l++;
		else
		{
			perror("The map must be rectangular.");
			exit(1);
		}
	}
	return 0;
}

void ft_window(void)
{
	t_long index;
	puts("imher");

	index.fd = open("test/test.ber" , O_RDONLY);
	index.str = get_next_line(index.fd);
	index.x = 0;
	while (index.str != NULL)
	{
		while(index.str[index.x])
		{
			if (index.str[index.x] == '0' || index.str[index.x] == '1' || index.str[index.x] == 'E' || index.str[index.x] == 'C' || index.str[index.x] == 'P')
				index.x++;
			else
			{
				perror(" hh 3afrite ");
				exit(1);
			}
			index.x++;
		}
		index.x = 0;
		index.str = get_next_line(index.fd);
	}
}

int main(void)
{
	t_long 	index;

    index.path1 = "./test/wall.xpm";
    index.path2 = "./test/eats.xpm";
    index.path3 = "./test/player.xpm";
    index.path4 = "./test/babb.xpm";
    index.fd = open("./test/test.ber", O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL)
	{
		//puts("im here");
		printf("%s\n" , strerror(errno));
		exit(1);
	}
	ft_window();
	check_size();
	sec_check();
	index.mlx = mlx_init();
	index.a = ft_size_window();
	index.i = ft_size_window2();
	index.win = mlx_new_window(index.mlx, index.a, index.i, " lo3ba za3ma ");
    index.img1 = mlx_xpm_file_to_image(index.mlx, index.path1, &index.x, &index.y);
    index.img2 = mlx_xpm_file_to_image(index.mlx, index.path2, &index.x, &index.y);
    index.img3 = mlx_xpm_file_to_image(index.mlx, index.path3, &index.x, &index.y);
    index.img4 = mlx_xpm_file_to_image(index.mlx, index.path4, &index.x, &index.y);
    check_event(&index);
    mlx_key_hook(index.win, key_hook, &index);
	mlx_loop(index.mlx);
}
