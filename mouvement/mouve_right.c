/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:47:38 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/10 16:47:41 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"


void	test2(t_long *index)
{
		mlx_put_image_to_window(index->mlx, index->win, index->img9, index->count1, index->count2);
		mlx_put_image_to_window(index->mlx, index->win, index->img12, 700, 300);
		index->eny = 0;
}

void	enemy_mouve_right(t_long *index)
{
	if (index->tab1[index->pos1][index->pos2 + 1] != '1' && index->tab1[index->pos1][index->pos2 + 1] != 'C')
	{
		index->tab1[index->pos1][index->pos2] = '0';
		index->pos2++;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
		xeny += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
		mlx_put_image_to_window(index->mlx, index->win, index->img11, xeny, yeny);
		index->tab1[index->pos1][index->pos2] = 'K';
	}
}


void	click_right(t_long *index)
{
	if (index->tab[index->line][index->idx + 1] == 'E')
	{
		index->e = ft_exit(index->tab);
		if (index->e == 0)
		{
			free(index->tab);
			exit(1);
		}
	}
    if (index->tab[index->line][index->idx + 1] != '1' && index->tab[index->line][index->idx + 1] != 'E' && index->eny == 1)
    {
        a++;
		enemy_mouve_right(index);
        index->idx++;
		if ((index->line) == index->pos1 && (index->idx) == index->pos2)
			test2(index);
        if (index->tab[index->line][index->idx] == 'C')
        {
            index->a = index->line;
            index->b = index->idx;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        index->count1 += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, index->count1, index->count2);
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_string_put(index->mlx, index->win, 0, 30, 1000, ft_itoa(a));
    }
}
