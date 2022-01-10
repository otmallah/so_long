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

typedef struct	s_long {
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	char	*path;
	char	*path2;
	int		x , y;
	int fd;
	char *s;
	char *str;
	int i , a;
}	t_long;

int    check_size(void)
{
	int k = 0, l = 0;
	int fd;
	char *str;

	fd = open("test/test.ber" , O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (0);
	k = strlen(str);
	while(str != NULL)  {
		l = strlen(str);
		if (l != k)
		{
			puts("map is not rectangular");
			exit(1);
		}
		str = get_next_line(fd);
	}
	return 0;
}

int	check_event(char *path, char *path2, t_long *index)
{
	int p = 0;
	int l = 0;

	index->i = 0;
	index->a = 0;
	while (index->str != NULL) {
		while (index->str[index->i]) {
			if (index->str[index->i] == '1')
				mlx_put_image_to_window(index->mlx, index->win, index->img1, p, l);
			else if (index->str[index->i] == '0')
				printf("0");
			else if (index->str[index->i] == 'E')
				printf("e");
			else if (index->str[index->i] == 'C')
				printf("c");
			else if (index->str[index->i] == 'P')
			{
				k = p;
				k2 = l;
				mlx_put_image_to_window(index->mlx, index->win, index->img2, p, l);
			}
			index->i++;
			p += 75;
		}
		p = 0;
		l += 76;
		index->str = get_next_line(index->fd);
		index->i = 0;
	}
	return 0;
}

int		check_event2(char *path, char *path2 , t_long *index)
{
	int e = 0;
	int k = 0;

	index->i = 0;
	index->a = 0;
	index->fd = open("test/test.ber" , O_RDONLY);
	index->str = get_next_line(index->fd);
	printf("%s" , index->str);
	if (index->str == NULL)
		return 0;
	while (index->str != NULL) {
		while (index->str[index->i])
		{
			puts("im here hh");
			if (index->str[index->i] == '1')
				mlx_put_image_to_window(index->mlx, index->win, index->img1, e, k);
			else if (index->str[index->i] == '0')
				printf("0");
			else if (index->str[index->i] == 'E')
				printf("e");
			else if (index->str[index->i] == 'C')
				printf("c");
			index->i++;
			e += 75;
		}
		e = 0;
		k += 76;
		index->str = get_next_line(index->fd);
		index->i = 0;
	}
	return 0;
}

int		key_hook(int keycode, t_long *index)
{
	index->path = "test/output-onlinepngtools.xpm";
	index->path2 = "test/open.xpm";

	if (keycode == 65361)
	{
		mlx_clear_window(index->mlx, index->win);
		check_event2(index->path, index->path2, index);
		k -= 75;
		mlx_put_image_to_window(index->mlx, index->win, index->img2, k, k2);
	}
	else if (keycode == 65363)
	{
		mlx_clear_window(index->mlx, index->win);
		check_event2(index->path, index->path2, index);
		k += 75;
		mlx_put_image_to_window(index->mlx, index->win, index->img2, k, k2);
	}
	else if (keycode == 65362)
	{
		mlx_clear_window(index->mlx, index->win);
		check_event2(index->path, index->path2, index);
		k2 -= 75;
		mlx_put_image_to_window(index->mlx, index->win, index->img2, k, k2);
	}
	else if (keycode == 65364)
	{
		mlx_clear_window(index->mlx, index->win);
		check_event2(index->path, index->path2, index);
		k2 += 75;
		mlx_put_image_to_window(index->mlx, index->win, index->img2, k, k2);
	}
}

int main(void)
{
	t_long 	index;
	index.path = "test/output-onlinepngtools.xpm";
	index.path2 = "test/open.xpm";

	index.fd = open("test/test.ber", O_RDONLY);
	check_size();
	index.str = get_next_line(index.fd);
	if (index.str == NULL)
		return 0;
	index.mlx = mlx_init();
	index.win = mlx_new_window(index.mlx, 1200, 610, " new window ");
	index.img1 = mlx_xpm_file_to_image(index.mlx, index.path, &index.x, &index.y);
	index.img2 = mlx_xpm_file_to_image(index.mlx, index.path2, &index.x, &index.y);
	check_event(index.path, index.path2, &index);
	mlx_key_hook(index.win, key_hook, &index);
	mlx_loop(index.mlx);
}
