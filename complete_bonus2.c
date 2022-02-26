/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_bonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:36:15 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/17 16:36:16 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sen_main_bon(t_long *id, char *file)
{
	if (id->yu == 0 && id->po == 0)
	{
		id->yu = find_position_index_k(id->tab1);
		id->po = find_position_line_k(id->tab1);
	}
	complete_map_bonus(id);
	ft_window_bonus(file);
	check_size_bonus(file);
	sec_check_bonus(file, id);
	id->mlx = mlx_init();
	id->e = ft_size_width(file);
	id->i = ft_size_height(file);
	id->win = mlx_new_window(id->mlx, id->e, id->i, "game");
	images_bonus(id);
	id->eny = 1;
	check_event(id);
	mlx_loop_hook(id->mlx, loop_hook, id);
	mlx_key_hook(id->win, key_hook, id);
	mlx_hook(id->win, 17, 0, ft_close, id);
	mlx_loop(id->mlx);
}

void	test_ber(char *file)
{
	char	*str;

	str = ft_strrchr(file, '.');
	if (ft_strcmp(str, ".ber") != 0)
	{
		write (1, "map should end with .ber", 25);
		exit(1);
	}
}
