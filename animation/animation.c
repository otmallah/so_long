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

#include "../so_long_bonus.h"

void	continue_drw(t_long *id);

void	ft_animation_player(t_long *id)
{
	if (id->xi >= 15)
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img1, 0, 0);
		mlx_put_image_to_window(id->mlx, id->win, id->img8, 0, 0);
	}
	if (id->xi >= 30)
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img1, 0, 0);
		mlx_put_image_to_window(id->mlx, id->win, id->img9, 0, 0);
	}
	if (id->xi >= 45)
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img1, 0, 0);
		mlx_put_image_to_window(id->mlx, id->win, id->img10, 0, 0);
	}
	if (id->xi >= 60)
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img1, 0, 0);
		mlx_put_image_to_window(id->mlx, id->win, id->img13, 0, 0);
	}
	continue_drw(id);
	id->xi++;
	if (id->xi == 125)
		id->xi = 0;
}

void	continue_drw(t_long *id)
{
	if (id->xi >= 75)
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img1, 0, 0);
		mlx_put_image_to_window(id->mlx, id->win, id->img14, 0, 0);
	}
	if (id->xi >= 90)
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img1, 0, 0);
		mlx_put_image_to_window(id->mlx, id->win, id->img15, 0, 0);
	}
	if (id->xi >= 105)
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img1, 0, 0);
		mlx_put_image_to_window(id->mlx, id->win, id->img16, 0, 0);
	}
	if (id->xi >= 120)
	{
		mlx_put_image_to_window(id->mlx, id->win, id->img1, 0, 0);
		mlx_put_image_to_window(id->mlx, id->win, id->img17, 0, 0);
	}
}
