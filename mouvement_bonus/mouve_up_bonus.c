/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_up_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:40:39 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 17:40:40 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	test(t_long *id)
{
	mlx_put_image_to_window(id->mlx, id->win, id->img12, 1000, 300);
	id->eny = 0;
}

void	ft_bon4(t_long	*id);

void	click_up_bonus(t_long *id)
{
	if (id->tab[id->line - 1][id->idx] == 'E')
	{
		id->e = ft_exit(id->tab);
		if (id->e == 0)
			exit(1);
	}
	if (id->tab[id->line - 1][id->idx] != '1'
		&& id->tab[id->line - 1][id->idx] != 'E' && id->eny == 1)
	{
		id->num_mv++;
		if (id->tab[id->line - 1][id->idx] == 'K')
			test(id);
		id->line--;
		if (id->tab[id->line][id->idx] == 'C')
		{
			id->a = id->line;
			id->b = id->idx;
		}
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->cb1, id->cb2);
		id->cb2 -= 76;
		mlx_put_image_to_window(id->mlx, id->win, id->img5, id->cb1, id->cb2);
		mlx_put_image_to_window(id->mlx, id->win, id->img3, id->cb1, id->cb2);
		ft_bon4(id);
	}
}

void	ft_bon4(t_long	*id)
{
	char	*str;

	mlx_put_image_to_window(id->mlx, id->win, id->img1, 76, 0);
	str = ft_itoa(id->num_mv);
	mlx_string_put(id->mlx, id->win, 80, 30, 0xFFFFFF, str);
	free(str);
}
