/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:27:31 by otmallah          #+#    #+#             */
/*   Updated: 2022/01/05 12:27:34 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int k;
int k2;
int o;
int cout;
int wall1;
int	wall2;


typedef struct	s_long {
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	char	*path;
	char	*path2;
	char	*path3;
	char	*path4;
	int		x , y;
	int		fd;
	char	*s;
	char	*str;
	int i , a;
}	t_long;

int		check_event2(t_long *index);

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

void	sec_check(void)
{
	t_long	index;
	int res;

	index.fd = open("test/test.ber" , O_RDONLY);
	index.str = get_next_line(index.fd);
	if (index.str == NULL)
		exit(1);
	index.x = 0;
	res = salam();
	printf("%d\n" , res);
	while (--res >= 0)
	{
		if (res == 0 || res == (res - 1))
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
			puts("map is not completed");
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
			puts("map is not rectangular");
			exit(1);
		}
	}
	return 0;
}

int	check_event(t_long *index)
{
	int p = 0;
	int l = 0;
	//t_long *index2;

	index->i = 0;
	index->a = 0;
	while (index->str != NULL) {
		while (index->str[index->i])
		{
			if (index->str[index->i] == '1')
			{
				mlx_put_image_to_window(index->mlx, index->win, index->img1, p, l);
				//printf("%d  %d\n " , wall1, wall2);
				cout++;
			}
			else if (index->str[index->i] == '0')
				o++;
			else if (index->str[index->i] == 'E')
				mlx_put_image_to_window(index->mlx, index->win, index->img4, p, l);
			else if (index->str[index->i] == 'C')
				mlx_put_image_to_window(index->mlx, index->win, index->img3, p, l);
			else if (index->str[index->i] == 'P')
			{
				k = p;
				k2 = l;
				mlx_put_image_to_window(index->mlx, index->win, index->img2, p, l);
			}
			index->i++;
			p += 76;
		}
		p = 0;
		l += 76;
		index->str = get_next_line(index->fd);
		index->i = 0;
	}
	return 0;
}

int		check_event2(t_long *index)
{
	int e = 0;
	int k = 0;

	index->i = 0;
	index->a = 0;
	index->fd = open("test/test.ber" , O_RDONLY);
	index->str = get_next_line(index->fd);
	if (index->str == NULL)
		return 0;
	while (index->str != NULL)
	{
		while (index->str[index->i])
		{
			if (index->str[index->i] == '1')
				mlx_put_image_to_window(index->mlx, index->win, index->img1, e, k);
			else if (index->str[index->i] == '0')
				o++;
			else if (index->str[index->i] == 'E')
			{
				o = e;
				cout = k;
				mlx_put_image_to_window(index->mlx, index->win, index->img4, e, k);
			}
			else if (index->str[index->i] == 'C')
				mlx_put_image_to_window(index->mlx, index->win, index->img3, e, k);
			index->i++;
			e += 76;
		}
		e = 0;
		k += 76;
		index->str = get_next_line(index->fd);
		index->i = 0;
	}
	return 0;
}

void	ft_wall(char *tab)
{
	int fd = open("test/test.ber" , O_RDONLY);
	char *str;
	int i = 0;
	int a = 0;

	str = get_next_line(fd);
	while (str != NULL)
	{
		while(str[i])
		{
			tab[a] = str[i];
			i++;
			a++;
		}
		i = 0;
		str = get_next_line(fd);
	}
	tab[a] = '\0';
}

int		key_hook(int keycode, t_long *index)
{
	index->fd = open("test/test.ber" , O_RDONLY);
	index->str = get_next_line(index->fd);
	char	*tab;

	index->i = 0;
	index->a = 0;
	while (index->str != NULL)
	{
		index->i = index->i + strlen(index->str);
		index->str = get_next_line(index->fd);
	}
	tab = (char *)malloc(sizeof(char) * (index->i + 1));
	ft_wall(tab);
	
	if (keycode == 65361)
	{
		mlx_clear_window(index->mlx, index->win);
		check_event2(index);
		k -= 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img2, k, k2);
	}
	else if (keycode == 65363)
	{
		mlx_clear_window(index->mlx, index->win);
		check_event2(index);
		k += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img2, k, k2);
	}
	else if (keycode == 65362)
	{
		mlx_clear_window(index->mlx, index->win);
		check_event2(index);
		k2 -= 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img2, k, k2);
	}
	else if (keycode == 65364)
	{
		mlx_clear_window(index->mlx, index->win);
		check_event2(index);
		k2 += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img2, k, k2);
	}
}

int main(void)
{
	t_long 	index;
	index.path = "test/output-onlinepngtools.xpm";
	index.path3 = "test/output-onlinepngtools-_1_-_1_.xpm";
	index.path2 = "test/open24.xpm";
	index.path4 = "test/tttt.xpm";

	index.fd = open("test/test.ber", O_RDONLY);
	check_size();
	sec_check();
	index.str = get_next_line(index.fd);
	if (index.str == NULL)
		return 0;
	index.mlx = mlx_init();
	index.win = mlx_new_window(index.mlx, 1650, 610, " lo3ba za3ma ");
	index.img1 = mlx_xpm_file_to_image(index.mlx, index.path, &index.x, &index.y);
	index.img2 = mlx_xpm_file_to_image(index.mlx, index.path2, &index.x, &index.y);
	index.img3 = mlx_xpm_file_to_image(index.mlx, index.path3, &index.x, &index.y);
	index.img4 = mlx_xpm_file_to_image(index.mlx, index.path4, &index.x, &index.y);
	check_event(&index);
	mlx_key_hook(index.win, key_hook, &index);
	mlx_get_screen_size(index.mlx, &index.x, &index.y);
	mlx_mouse_show(index.mlx, index.win);
	//mlx_key_hook(index.win, key_hook, &index);
	// mlx_flush_event(index);
	// mlx_int_get_visual(&index);
	mlx_loop(index.mlx);
}

