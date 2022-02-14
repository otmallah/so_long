/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:46:29 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/10 16:46:30 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

void	test(t_long *index)
{
	//mlx_put_image_to_window(index->mlx, index->win, index->img9, index->count1, index->count2);
	mlx_put_image_to_window(index->mlx, index->win, index->img10, 700, 300);
	index->eny = 0;
}

void	enemy_mouve_up(t_long *index)
{
	if (index->tab1[index->pos1 - 1][index->pos2] != '1' && index->tab1[index->pos1 - 1][index->pos2] != 'C')
	{
		index->tab1[index->pos1][index->pos2] = '0';
		index->pos1--;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
		yeny -= 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
		mlx_put_image_to_window(index->mlx, index->win, index->img11, xeny, yeny);
		index->tab1[index->pos1][index->pos2] = 'K';
	}
}

void	click_up(t_long *index)
{
	if (index->tab[index->line - 1][index->idx] == 'E')
	{
		index->e = ft_exit(index->tab);
		if (index->e == 0)
		{
			free(index->tab);
			exit(1);
		}
	}
    if (index->tab[index->line - 1][index->idx] != '1' && index->tab[index->line - 1][index->idx] != 'E' && index->eny == 1)
    {
		enemy_mouve_up(index);
		a++;
    	index->line--;
		if ((index->line) == index->pos1 && index->idx == index->pos2)
			test(index);
        if (index->tab[index->line][index->idx] == 'C')
        {
            index->a = index->line;
            index->b = index->idx;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        index->count2 -= 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, index->count1, index->count2);
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_string_put(index->mlx, index->win, 0, 30, 1000, ft_itoa(a));
    }
}
