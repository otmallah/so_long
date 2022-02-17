/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_down_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:37:51 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 17:37:52 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_bon1(t_long	*id);

void	test3(t_long *id)
{
	mlx_put_image_to_window(id->mlx, id->win, id->img12, 1000, 300);
	id->eny = 0;
}

void	ft_enemy(t_long *id)
{
	if (id->tab1[id->poss1 + 1][id->poss2] == '0')
	{
		id->poss1++;
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
		id->yy += 76;
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->xy, id->yy);
		mlx_put_image_to_window(id->mlx, id->win, id->img11, id->xy, id->yy);
	}
}

void	click_down_bonus(t_long *id)
{
	if (id->tab[id->line + 1][id->idx] == 'E')
	{
		id->e = ft_exit(id->tab);
		if (id->e == 0)
			exit(1);
	}
	if (id->tab[id->line + 1][id->idx] != '1'
		&& id->tab[id->line + 1][id->idx] != 'E' && id->eny == 1)
	{
		//ft_enemy(id);
		id->num_mv++;
		if (id->tab[id->line + 1][id->idx] == 'K')
			test3(id);
		id->line++;
		if (id->tab[id->line][id->idx] == 'C')
		{
			id->a = id->line;
			id->b = id->idx;
		}
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->cb1, id->cb2);
		id->cb2 += 76;
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->cb1, id->cb2);
		mlx_put_image_to_window(id->mlx, id->win, id->img3, id->cb1, id->cb2);
		ft_bon1(id);
	}
}

void	ft_bon1(t_long	*id)
{
	char	*str;

	mlx_put_image_to_window(id->mlx, id->win, id->img1, 76, 0);
	str = ft_itoa(id->num_mv);
	mlx_string_put(id->mlx, id->win, 80, 30, 0xFFFFFF, str);
	free(str);
}
