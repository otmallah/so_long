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

void	test4(t_long *index)
{
    printf("%d , %d\n" , x, y );
		mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
		mlx_put_image_to_window(index->mlx, index->win, index->img9, x, y);
		mlx_put_image_to_window(index->mlx, index->win, index->img10, 700, 300);
		index->eny = 0;
}

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
    	if(index->tab1[index->line][index->idx - 1] == 'K')
		    test4(index);
        if (index->tab[index->line][index->idx - 1] != '1' && index->tab[index->line][index->idx - 1] != 'E' && index->eny == 1)
        {
            a++;
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
		    mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		    mlx_string_put(index->mlx, index->win, 0, 30, 1000, ft_itoa(a));
        }
}
