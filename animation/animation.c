/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:40:33 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/15 14:43:13 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

void    ft_animation_player(t_long *index)
{
    if (index->xani >= 15)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->img8, 0, 0);
	}
	if (index->xani >= 30)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->img9, 0, 0);
	}
	if (index->xani >= 45)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->img10, 0, 0);	
	}
	if (index->xani >= 60)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->img13, 0, 0);
	}
    if (index->xani >= 75)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->img14, 0, 0);
	}
    if (index->xani >= 90)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->img15, 0, 0);
	}
    if (index->xani >= 105)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->img16, 0, 0);
	}
    if (index->xani >= 120)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 0, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->img17, 0, 0);
	}
	index->xani++;
	if (index->xani == 125)
		index->xani = 0;
}
