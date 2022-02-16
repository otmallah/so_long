/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:47:38 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/10 16:47:41 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	click_right(t_long *id)
{
	if (id->tab[id->line1][id->idx1 + 1] == 'E')
	{
		id->e = ft_exit(id->tab);
		if (id->e == 0)
		{
			free(id->tab);
			exit(1);
		}
	}
	if (id->tab[id->line1][id->idx1 + 1] != '1'
		&& id->tab[id->line1][id->idx1 + 1] != 'E')
	{
		id->idx1++;
		if (id->tab[id->line1][id->idx1] == 'C')
		{
			id->a = id->line1;
			id->b = id->idx1;
		}
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->c1, id->c2);
		id->c1 += 76;
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->c1, id->c2);
		mlx_put_image_to_window(id->mlx, id->win, id->img3, id->c1, id->c2);
	}
}
