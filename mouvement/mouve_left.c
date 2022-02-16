/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:47:05 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/10 16:47:08 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	click_left(t_long *index)
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
    if (index->tab[index->line][index->idx - 1] != '1' && index->tab[index->line][index->idx - 1] != 'E')
    {
		index->num_mv++;
        index->idx--;
        if (index->tab[index->line][index->idx] == 'C')
        {
            index->a = index->line;
            index->b = index->idx;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        index->count1 -= 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, index->count1, index->count2);
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 76, 0);
		mlx_string_put(index->mlx, index->win, 80, 30, 0xFFFFFF, ft_itoa(index->num_mv));
    }
}
