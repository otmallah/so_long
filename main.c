/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:27:31 by otmallah          #+#    #+#             */
/*   Updated: 2022/01/05 12:27:34 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int u;
int d;
int r;
int l;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	char	*path4;
	int		height;
	int		width;
	int		x;
	int		y;
	char	*path;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	static int a = 1;
	static int c = 1;
	int b;
	if (keycode == 126)
	{
		b = 1;
		mlx_clear_window(vars->mlx, vars->win);
		while (b < 1000)
		{	
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2, b, 625);
			b += 50;
		}
		c -= 40;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, a, c);
	}
	else if (keycode == 123)
	{
		mlx_clear_window(vars->mlx, vars->win);
		while (b < 1000)
		{	
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2, b, 625);
			b += 50;
		}
		a -= 40;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, a, c);
	}
	else if (keycode == 124)
	{
		b = 1;
		mlx_clear_window(vars->mlx, vars->win);
		while (b < 1000)
		{	
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2, b, 625);
			b += 50;
		}
		a += 40;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, a, c);
	}
	else if (keycode == 125)
	{
		b = 1;
		mlx_clear_window(vars->mlx, vars->win);
		while (b < 1000)
		{	
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2, b, 625);
			b += 50;
		}
		c += 40;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, a, c);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char *path = "test/output-onlinepngtools.xpm";
	char *path3 = "test/output-onlinepngtools-_3_.xpm";
	char *path2 = "test/output-onlinepngtools-_4_.xpm";
	vars.path4 = "test/tttt.xpm";
	int x;
	int res;
	int y;
	int a = 1;
	int b = 1;
	int c = 1;
	int d = 1;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 700, "wach");
	vars.img = mlx_xpm_file_to_image(vars.mlx, path, &vars.width, &vars.height);
	vars.img3 = mlx_xpm_file_to_image(vars.mlx, path3, &vars.x, &vars.y);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 530, 1);
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, path2, &x, &y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img2, 1, 625);
	while (a < 1000)
	{	
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img2, a, 625);
		a += 76;
	}
	while (b < 1000)
	{	
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img2, 1, b);
		b += 76;
	}
	while (c < 1000)
	{	
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img2, c, 1);
		c += 76;
	}
	while (d < 1000)
	{	
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img2, 930, d);
		d += 76;
	}
	mlx_loop(vars.mlx);
}
