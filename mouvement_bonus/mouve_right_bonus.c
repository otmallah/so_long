/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_right_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:39:57 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 17:39:58 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_bon3(t_long	*id);

void	test2(t_long *id)
{
	mlx_put_image_to_window(id->mlx, id->win, id->img12, 1000, 300);
	id->eny = 0;
}

void	ft_enemy3(t_long *id)
{
	if (id->tab1[id->poss1][id->poss2 + 1] == '0')
	{
		id->poss2++;
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
		id->xy += 76;
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
		mlx_put_image_to_window(id->mlx, id->win, id->img11, id->xy, id->yy);
	}
}

void	click_right_bonus(t_long *id)
{
	if (id->tab[id->line][id->idx + 1] == 'E')
	{
		id->e = ft_exit(id->tab);
		if (id->e == 0)
			exit(1);
	}
	if (id->tab[id->line][id->idx + 1] != '1'
		&& id->tab[id->line][id->idx + 1] != 'E' && id->eny == 1)
	{
		//ft_enemy3(id);
		id->num_mv++;
		if (id->tab[id->line][id->idx + 1] == 'K')
			test2(id);
		id->idx++;
		if (id->tab[id->line][id->idx] == 'C')
		{
			id->a = id->line;
			id->b = id->idx;
		}
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->cb1, id->cb2);
		id->cb1 += 76;
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->cb1, id->cb2);
		mlx_put_image_to_window(id->mlx, id->win, id->img3, id->cb1, id->cb2);
		ft_bon3(id);
	}
}

void	ft_bon3(t_long	*id)
{
	char	*str;

	mlx_put_image_to_window(id->mlx, id->win, id->img1, 76, 0);
	str = ft_itoa(id->num_mv);
	mlx_string_put(id->mlx, id->win, 80, 30, 0xFFFFFF, str);
	free(str);
}
