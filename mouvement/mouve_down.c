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

void	utils_move_down(t_long *index)
{
	char *str;
	static int a;
	char *c = ft_itoa(a);
	index->str1 = ft_strjoin("move num : ", c);
	a++;
}

void	click_down(t_long *index)
{
	if (index->tab[index->line + 1][index->idx] == 'E')
	{
		index->e = ft_exit(index->tab);
		if (index->e == 0)
		{
			free(index->tab);
			exit(1);
		}
	}
    if (index->tab[index->line + 1][index->idx] != '1' && index->tab[index->line + 1][index->idx] != 'E')
    {
		x++;
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
		mlx_string_put(index->mlx, index->win, 76, 50, 1000, "number move ");
   }
}
