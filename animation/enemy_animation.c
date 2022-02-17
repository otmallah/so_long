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

void	ft_eny(t_long *id);

void	ft_enemy_animation(t_long *i)
{
	if (i->yi <= 5)
	{
		mlx_put_image_to_window(i->mlx, i->win, i->img5, i->xy, i->yy);
		mlx_put_image_to_window(i->mlx, i->win, i->img11, i->xy, i->yy);
	}
	else if (i->yi <= 10)
	{
		if (i->tab1[i->po][i->yu + 1] != '1')
		{
			mlx_put_image_to_window(i->mlx, i->win, i->img5, i->xy, i->yy);
			if (i->yi == 6)
			{
				i->yu++;
				i->xy += 76;
				i->tab[i->po][i->yu] = 'K';
			}
			mlx_put_image_to_window(i->mlx, i->win, i->img5, i->xy, i->yy);
			mlx_put_image_to_window(i->mlx, i->win, i->img11, i->xy, i->yy);
		}
	}
	else if (i->yi <= 15)
		ft_eny(i);
	if (i->yi == 15)
		i->yi = 0;
	i->yi++;
}

void	ft_eny(t_long *id)
{
	if (id->tab1[id->po][id->yu - 1] != '1')
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
		if (id->yi == 11)
		{
			id->tab[id->po][id->yu] = 'K';
			id->yu--;
			id->xy -= 76;
			id->tab[id->po][id->yu] = 'K';
		}
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
		mlx_put_image_to_window(id->mlx, id->win, id->img11, id->xy, id->yy);
	}
}
