/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:18:27 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/17 16:33:19 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_long *index)
{
	if (index->idx == 0 && index->line == 0)
	{
		index->idx = find_position_index_bonus(index->tab);
		index->line = find_position_line_bonus(index->tab);
	}
	if (index->a != 0 && index->b != 0)
	{
		index->tab[index->a][index->b] = '0';
		index->tab1[index->a][index->b] = '0';
	}
	if (keycode == 124 || keycode == 2)
		click_right_bonus(index);
	else if (keycode == 123 || keycode == 0)
		click_left_bonus(index);
	else if (keycode == 126 || keycode == 13)
		click_up_bonus(index);
	else if (keycode == 125 || keycode == 1)
		click_down_bonus(index);
	else if (keycode == 53)
		exit(1);
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

int	ft_close(void)
{
	exit(0);
	return (0);
}

void	images_bonus(t_long *i)
{
	i->iimg2 = mlx_xpm_file_to_image(i->mlx, "./t/eats.xpm", &i->x, &i->y);
	i->iimg7 = mlx_xpm_file_to_image(i->mlx, "./t/eats2.xpm", &i->x, &i->y);
	i->iimg8 = mlx_xpm_file_to_image(i->mlx, "./t/eats3.xpm", &i->x, &i->y);
	i->iimg9 = mlx_xpm_file_to_image(i->mlx, "./t/eats4.xpm", &i->x, &i->y);
	i->iimg10 = mlx_xpm_file_to_image(i->mlx, "./t/eats5.xpm", &i->x, &i->y);
	i->img12 = mlx_xpm_file_to_image(i->mlx, "./t/Death.xpm", &i->x, &i->y);
	i->img11 = mlx_xpm_file_to_image(i->mlx, "./t/any.xpm", &i->x, &i->y);
	i->img1 = mlx_xpm_file_to_image(i->mlx, "./t/wall.xpm", &i->x, &i->y);
	i->img2 = mlx_xpm_file_to_image(i->mlx, "./t/eats.xpm", &i->x, &i->y);
	i->img3 = mlx_xpm_file_to_image(i->mlx, "./t/anim1.xpm", &i->x, &i->y);
	i->img4 = mlx_xpm_file_to_image(i->mlx, "./t/door.xpm", &i->x, &i->y);
	i->img5 = mlx_xpm_file_to_image(i->mlx, "./t/gras.xpm", &i->x, &i->y);
	i->img6 = mlx_xpm_file_to_image(i->mlx, "./t/DOR.xpm", &i->x, &i->y);
	i->img8 = mlx_xpm_file_to_image(i->mlx, "./t/anim1.xpm", &i->x, &i->y);
	i->img9 = mlx_xpm_file_to_image(i->mlx, "./t/anim2.xpm", &i->x, &i->y);
	i->img10 = mlx_xpm_file_to_image(i->mlx, "./t/anim3.xpm", &i->x, &i->y);
	i->img13 = mlx_xpm_file_to_image(i->mlx, "./t/anim4.xpm", &i->x, &i->y);
	i->img14 = mlx_xpm_file_to_image(i->mlx, "./t/anim5.xpm", &i->x, &i->y);
	i->img15 = mlx_xpm_file_to_image(i->mlx, "./t/anim6.xpm", &i->x, &i->y);
	i->img16 = mlx_xpm_file_to_image(i->mlx, "./t/anim7.xpm", &i->x, &i->y);
	i->img17 = mlx_xpm_file_to_image(i->mlx, "./t/anim8.xpm", &i->x, &i->y);
}

int	number_coin(t_long *index)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;
	while (index->tab[j])
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
	return (a);
}
