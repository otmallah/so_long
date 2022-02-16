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

void	click_down(t_long *index)
{
	char *str;
	if (index->tab[index->line1 + 1][index->idx1] == 'E')
	{
		index->e = ft_exit(index->tab);
		if (index->e == 0)
		{
			free(index->tab);
			exit(1);
		}
	}
    if (index->tab[index->line1 + 1][index->idx1] != '1' && index->tab[index->line1 + 1][index->idx1] != 'E')
    {
        index->line1++;
        if (index->tab[index->line1][index->idx1] == 'C')
        {
            index->a = index->line1;
            index->b = index->idx1;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
	    index->count2 += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, index->count1, index->count2);
   }
}
