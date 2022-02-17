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
	system("leaks so_long");
	mlx_loop(id->mlx);
}
