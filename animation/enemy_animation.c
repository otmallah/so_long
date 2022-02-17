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
	//printf("line = %d  index = %d \n", id->poss1, id->poss2);
	//printf("%s \n", id->tab1[1]);
	if (id->yi >= 0)
	{
			mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
			mlx_put_image_to_window(id->mlx, id->win, id->img11, id->xy, id->yy);
	}
	if (id->yi == 15)
		id->yi = 0;
	id->yi++;
}
0