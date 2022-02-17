/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:42:48 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 21:42:49 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check(char c, t_long *index, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(index->mlx, index->win, index->img1, i, j);
	else if (c == '0')
		mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
	else if (c == 'C')
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
		mlx_put_image_to_window(index->mlx, index->win, index->img2, i, j);
	}
	else if (c == 'P')
	{
		index->c1 = i;
		index->c2 = j;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
		mlx_put_image_to_window(index->mlx, index->win, index->img3, i, j);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
		mlx_put_image_to_window(index->mlx, index->win, index->img4, i, j);
	}
}

void	ft_check_ev(char *str, t_long *index, int i, int j)
{
	int	a;

	a = 0;
	while (str[a])
	{
		check(str[a], index, i, j);
		a++;
		i += 76;
	}
}

int	check_event(t_long *index)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	j = 0;
	while (index->tab[a] != NULL)
	{
		ft_check_ev(index->tab[a], index, i, j);
		a++;
		i = 0;
		j += 76;
	}
	return (0);
}

int	ft_exit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j] != NULL)
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'C')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	key_hook(int keycode, t_long *index)
{
	if (index->idx1 == 0 && index->line1 == 0)
	{
		index->idx1 = find_position_index(index->tab);
		index->line1 = find_position_line(index->tab);
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
	return (0);
}

int	ft_close(void)
{
	exit(0);
	return (0);
}

void	images(t_long	*id)
{
	id->img1 = mlx_xpm_file_to_image(id->mlx, "./test/wall.xpm", &id->x, &id->y);
	id->img2 = mlx_xpm_file_to_image(id->mlx, "./test/eats.xpm", &id->x, &id->y);
	id->img3 = mlx_xpm_file_to_image(id->mlx, "./test/player.xpm", &id->x, &id->y);
	id->img4 = mlx_xpm_file_to_image(id->mlx, "./test/door.xpm", &id->x, &id->y);
	id->img5 = mlx_xpm_file_to_image(id->mlx, "./test/grass.xpm", &id->x, &id->y);
	id->img6 = mlx_xpm_file_to_image(id->mlx, "./test/DOR.xpm", &id->x, &id->y);
}

void	sec_main(t_long	*index, char *file)
{
	index->fd = open(file, O_RDONLY);
	index->str = get_next_line(index->fd);
	if (index->str == NULL || index->str[0] == '\0')
		exit(1);
	index->tab = key_event(index->file, index);
	index->tab1 = key_event_enemy(index->file, index);
	complete_map(index);
	ft_window(file);
	check_size(file);
	sec_check(file, index);
	index->mlx = mlx_init();
	index->e = ft_size_width(file);
	index->i = ft_size_height(file);
	index->win = mlx_new_window(index->mlx, index->e, index->i, " lo3ba za3ma ");
	images(index);
	check_event(index);
	mlx_key_hook(index->win, key_hook, index);
	mlx_hook(index->win, 17, 0, ft_close, index);
	system("leaks so_long");
	mlx_loop(index->mlx);
}

int	main(int ac, char **av)
{
	t_long	index;

	if (ac == 2)
	{
		index.file = av[1];
		sec_main(&index, av[1]);
	}
	else
		write(1, "more arg\n", 9);
}
