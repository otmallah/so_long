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

// int		find_position_index_c(char **tab)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (tab[j])
// 	{
// 		while (tab[j][i])
// 		{
// 			if (tab[j][i] == 'C')
// 				return i;
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 	}
// 	return 0;
// }

// int		find_position_line_c(char **tab)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (tab[j])
// 	{
// 		while (tab[j][i])
// 		{
// 			if (tab[j][i] == 'C')
// 				return j;
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 	}
// 	return 0;
// }


// void    animation(t_long *index, int x, int y)
// {
//     if (index->pok2 >= 0)
// 	{
// 		mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
// 		mlx_put_image_to_window(index->mlx, index->win, index->iimg2, x, y);
// 	}
// 	if (index->pok2 >= 15)
// 	{
// 		mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
// 		mlx_put_image_to_window(index->mlx, index->win, index->iimg7, x, y);
// 	}
// 	if (index->pok2 >= 30)
// 	{
// 		mlx_put_image_to_window(index->mlx, index->win, index->img5,x, y);
// 		mlx_put_image_to_window(index->mlx, index->win, index->iimg8, x, y);	
// 	}
// 	if (index->pok2 >= 45)
// 	{
// 		mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
// 		mlx_put_image_to_window(index->mlx, index->win, index->iimg9, x, y);
// 	}
// 	if (index->pok2 >= 60)
// 	{
// 		mlx_put_image_to_window(index->mlx, index->win, index->img5, x,y);
// 		mlx_put_image_to_window(index->mlx, index->win, index->iimg10,x, y);
// 	}
// 	index->pok2++;
// 	if (index->pok2 == 75)
// 		index->pok2 = 0;
// }

// void    ft_coin_animation_eats(t_long *index)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     x = find_position_index_c(index->tab1);
//     y = find_position_line_c(index->tab1);
//     printf("%d \n" , x);
//     //et2x = find_position_index(index->tab);
//     //et2y = find_position_line(index->tab);
//     while (index->tab[j])
//     {
//         while (index->tab[j][i])
//         {
//             if (index->tab[j][i] == 'C')
//             {
//                 animation(index);
//             }
//             i++;
//         }
//         i = 0;
//         j++;
//     }
// }
