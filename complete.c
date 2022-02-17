/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:55:27 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/17 15:55:32 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	exit(0);
	return (0);
}

void	images(t_long	*id)
{
	id->img1 = mlx_xpm_file_to_image(id->mlx, "./t/wall.xpm", &id->x, &id->y);
	id->img2 = mlx_xpm_file_to_image(id->mlx, "./t/eats.xpm", &id->x, &id->y);
	id->img3 = mlx_xpm_file_to_image(id->mlx, "./t/anim1.xpm", &id->x, &id->y);
	id->img4 = mlx_xpm_file_to_image(id->mlx, "./t/door.xpm", &id->x, &id->y);
	id->img5 = mlx_xpm_file_to_image(id->mlx, "./t/gras.xpm", &id->x, &id->y);
	id->img6 = mlx_xpm_file_to_image(id->mlx, "./t/DOR.xpm", &id->x, &id->y);
}

void	sec_main(t_long	*index, char *file)
{
	index->fd = open(file, O_RDONLY);
	index->str = get_next_line(index->fd);
	if (index->str == NULL || index->str[0] == '\0')
		exit(1);
	free(index->str);
	index->tab = key_event(index->file, index);
	index->tab1 = key_event_enemy(index->file, index);
	complete_map(index);
	ft_window(file);
	check_size(file);
	sec_check(file, index);
	index->mlx = mlx_init();
	index->e = ft_size_width(file);
	index->i = ft_size_height(file);
	index->win = mlx_new_window(index->mlx, index->e, index->i, "game");
	images(index);
	check_event(index);
	mlx_key_hook(index->win, key_hook, index);
	mlx_hook(index->win, 17, 0, ft_close, index);
	system("leaks so_long");
	mlx_loop(index->mlx);
}

int	ft_exit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j] != NULL)
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'C')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
