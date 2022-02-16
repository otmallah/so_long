/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_left_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:38:59 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 17:39:00 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long_bonus.h"

void	test4(t_long *index)
{
	mlx_put_image_to_window(index->mlx, index->win, index->img12, 1000, 300);
	index->eny = 0;
}

void	click_left_bonus(t_long *index)
{
	if (index->tab[index->line][index->idx- 1] == 'E')
	{
		index->e = ft_exit(index->tab);
		if (index->e == 0)
		{
			free(index->tab);
			exit(1);
		}
	}
    if (index->tab[index->line][index->idx - 1] != '1' && index->tab[index->line][index->idx - 1] != 'E' && index->eny == 1)
    {
    	index->num_mv++;
        if (index->tab[index->line][index->idx - 1] == 'K')
            test4(index);
        index->idx--;
        if (index->tab[index->line][index->idx] == 'C')
        {
            index->a = index->line;
            index->b = index->idx;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->countb1, index->countb2);
        index->countb1 -= 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->countb1, index->countb2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, index->countb1, index->countb2);
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 76, 0);
		mlx_string_put(index->mlx, index->win, 80, 30, 0xFFFFFF, ft_itoa(index->num_mv));
    }
}
