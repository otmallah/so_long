/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:40:42 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/15 14:40:44 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_enemy_animation(t_long *id)
{
	if (id->yi <= 15)
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
		mlx_put_image_to_window(id->mlx, id->win, id->img11, id->xy, id->yy);
	}
	else if (id->yi <= 30)
	{
		if (id->tab1[id->posss1][id->posss2 + 1] != '1')
		{
			mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
			if (id->yi == 16)
			{
				id->tab[id->posss1][id->posss2] = '0';
				id->posss2++;
				id->xy += 76;
				id->tab[id->posss1][id->posss2] = 'K';
			}
			mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
			mlx_put_image_to_window(id->mlx, id->win, id->img11, id->xy, id->yy);
		}
	}
	else if (id->yi <= 45)
	{
		if (id->tab1[id->posss1][id->posss2 - 1] != '1')
		{
			mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
			if (id->yi == 31)
			{
				id->tab[id->posss1][id->posss2] = '0';
				id->posss2--;
				id->xy -= 76;
				id->tab[id->posss1][id->posss2] = 'K';
			}
			mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
			mlx_put_image_to_window(id->mlx, id->win, id->img11, id->xy, id->yy);
		}	
	}
	if (id->yi == 60)
		id->yi = 0;
	id->yi++;
}
