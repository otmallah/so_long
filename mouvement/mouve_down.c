/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:45:57 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/10 16:46:00 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	test3(t_long *index)
{
		mlx_put_image_to_window(index->mlx, index->win, index->img9, index->count1, index->count2);
		mlx_put_image_to_window(index->mlx, index->win, index->img10, 700, 300);
		index->eny = 0;
}

void	enemy_move_down(t_long *index)
{
	if (index->tab1[index->pos1 + 1][index->pos2] != '1' && index->tab1[index->pos1 + 1][index->pos2] != 'C')
	{
		//index->tab[index->pos1][index->pos2] = '0';
		index->tab1[index->pos1][index->pos2] = '0';
		index->pos1++;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
		//if (index->line > yeny)
		yeny += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
		mlx_put_image_to_window(index->mlx, index->win, index->img11, xeny, yeny);
		//index->tab[index->pos1][index->pos2] = 'K';
		index->tab1[index->pos1][index->pos2] = 'K';
	}
}

void	click_down(t_long *index)
{
	char *str;
	if (index->tab[index->line + 1][index->idx] == 'E')
	{
		index->e = ft_exit(index->tab);
		if (index->e == 0)
		{
			free(index->tab);
			exit(1);
		}
	}
    if (index->tab[index->line + 1][index->idx] != '1' && index->tab[index->line + 1][index->idx] != 'E' && index->eny == 1)
    {
		a++;
		enemy_move_down(index);
        index->line++;
		if ((index->line) == index->pos1 && index->idx == index->pos2)
			test3(index);
        if (index->tab[index->line][index->idx] == 'C')
        {
            index->a = index->line;
            index->b = index->idx;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
	    index->count2 += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, index->count1, index->count2);
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_string_put(index->mlx, index->win, 0, 30, 0xFFFFFF, ft_itoa(a));
   }
}
