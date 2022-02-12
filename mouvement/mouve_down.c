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


void    enemy4(t_long *index)
{
    puts("o");
	printf("%c \n" , index->tab1[pos1 + 1][pos2]);
	
	if (index->tab1[pos1 + 1][pos2] != '1')
	{
		pos1++;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
		y += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
		mlx_put_image_to_window(index->mlx, index->win, index->img11, x, y);
	}
	else
		puts("ee");
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
	if(index->tab[index->line][index->idx] == 'K')
		test3(index);
	//enemy4(index);
    if (index->tab[index->line + 1][index->idx] != '1' && index->tab[index->line + 1][index->idx] != 'E' && index->tab[index->line + 1][index->idx] != 'K' && index->eny == 1)
    {
		a++;
        index->line++;
        if (index->tab[index->line][index->idx] == 'C')
        {
            index->a = index->line;
            index->b = index->idx;
        }
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
	    index->count2 += 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, index->count1, index->count2);
        mlx_put_image_to_window(index->mlx, index->win, index->img3, index->count1, index->count2);
		//str = utils_move_down();
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_string_put(index->mlx, index->win, 0, 30, 1000, ft_itoa(a));
   }
}
