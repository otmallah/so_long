#include "../so_long.h"

void    ft_animation_coin(t_long *index)
{
    puts("js");
    if (index->pok >= 0)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 152, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->iimg2, 152, 0);
	}
	if (index->pok >= 15)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 152, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->iimg7, 152, 0);
	}
	if (index->pok >= 30)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 152, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->iimg8, 152, 0);	
	}
	if (index->pok >= 45)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 152, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->iimg9, 152, 0);
	}
	if (index->pok >= 60)
	{
		mlx_put_image_to_window(index->mlx, index->win, index->img1, 152, 0);
		mlx_put_image_to_window(index->mlx, index->win, index->iimg10,152, 0);
	}
	index->pok++;
	if (index->pok == 75)
		index->pok = 0;
} 