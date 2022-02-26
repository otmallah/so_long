/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:33:05 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/17 17:33:06 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		index->cb1 = i;
		index->cb2 = j;
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
		if (str[a] == 'K')
		{
			index->xy = i;
			index->yy = j;
			mlx_put_image_to_window(index->mlx, index->win, index->img5, i, j);
			mlx_put_image_to_window(index->mlx, index->win, index->img11, i, j);
		}
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

int	loop_hook(t_long *index)
{
	char	*str;
	int		r;

	r = number_coin(index);
	str = ft_itoa(r);
	mlx_put_image_to_window(index->mlx, index->win, index->img1, 228, 0);
	mlx_string_put(index->mlx, index->win, 240, 30, 0xFFFFFF, str);
	free(str);
	ft_animation_player(index);
	ft_animation_coin(index, 152, 0);
	ft_enemy_animation(index);
	return (0);
}

int	main(int ac, char **av)
{
	t_long	index;
	char	*str;

	if (ac == 2)
	{
		index.fd = open(av[1], O_RDONLY);
		index.str = get_next_line(index.fd);
		if (index.str == NULL || index.str[0] == '\0')
			exit(1);
		test_ber(av[1]);
		free(index.str);
		index.file = av[1];
		index.tab = key_event_bonus(index.file, &index);
		index.tab1 = key_event_enemy_bonus(index.file, &index);
		sen_main_bon(&index, av[1]);
	}
	else
		write (1, "more arg\n", 10);
}
