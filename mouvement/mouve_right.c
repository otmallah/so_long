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

void	click_right(t_long *index)
{
	if (index->tab[index->line1][index->idx1 + 1] == 'E')
	{
		index->e = ft_exit(index->tab);
		if (index->e == 0)
		{
			free(index->tab);
			exit(1);
		}
	}
    if (index->tab[index->line1][index->idx1 + 1] != '1' && index->tab[index->line1][index->idx1 + 1] != 'E')
    {
        index->idx1++;
        if (index->tab[index->line1][index->idx1] == 'C')
        {
            index->a = index->line1;
            index->b = index->idx1;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        index->count1 += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, index->count1, index->count2);
    }
}
