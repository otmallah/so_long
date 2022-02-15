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


#include "../so_long.h"

void    ft_enemy_animation(t_long *index)
{
    if (index->yani >= 0)
    {
        mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
        mlx_put_image_to_window(index->mlx, index->win, index->img11, xeny, yeny);
    }
    if (index->yani >=20)
    {
        mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
        if (index->yani == 20)
            xeny += 76;
        mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
        mlx_put_image_to_window(index->mlx, index->win, index->img11, xeny, yeny);
    }
    if (index->yani >= 40)
    {
        mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
        if (index->yani == 40)
            xeny -= 76;
        mlx_put_image_to_window(index->mlx, index->win, index->img5, xeny, yeny);
        mlx_put_image_to_window(index->mlx, index->win, index->img11, xeny, yeny);  
    }
    if(index->yani == 60)
        index->yani = 0;
    index->yani++;
}