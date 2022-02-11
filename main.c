#include "so_long.h"

void	mouvement(t_long *index)
{

	puts("knnde");
	int x = 76;
	int y = 76;
	while (x <= 156)
	{
    	mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
		x += 76;
    	mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
    	mlx_put_image_to_window(index->mlx, index->win, index->img2, x, y);
		x -= 50;
    	mlx_put_image_to_window(index->mlx, index->win, index->img2, x, y);
	}
}

int key_hook(int keycode,  t_long *index)
{
	int x = 76;
	int y = 76;
		mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
		x += 76;
    	mlx_put_image_to_window(index->mlx, index->win, index->img5, x, y);
    	mlx_put_image_to_window(index->mlx, index->win, index->img2, x, y);
		x -= 50;
    	mlx_put_image_to_window(index->mlx, index->win, index->img2, x, y);
	return 0;
}

int main(int ac, char **av)
{
	t_long 	index;

    //index.fd = open(av[1], O_RDONLY);
	//index.str = get_next_line(index.fd);
	// if (index.str == NULL || index.str[0] == '\0')
	// 	exit(1);
	index.file = av[1];
	// ft_complete_map(av[1], &index);
	// ft_window(av[1]);
	// check_size(av[1]);
	// sec_check(av[1]);
	index.mlx = mlx_init();
	//index.e = ft_size_width(av[1]);
	///index.i = ft_size_height(av[1]);
	index.win = mlx_new_window(index.mlx, 1080, 650, " lo3ba za3ma ");
    index.img2 = mlx_xpm_file_to_image(index.mlx, "./test/eats.xpm", &index.x, &index.y);
    index.img7 = mlx_xpm_file_to_image(index.mlx, "./test/eats2.xpm", &index.x, &index.y);
    index.img8 = mlx_xpm_file_to_image(index.mlx, "./test/eats3.xpm", &index.x, &index.y);
    index.img9 = mlx_xpm_file_to_image(index.mlx, "./test/eats4.xpm", &index.x, &index.y);
    index.img10 = mlx_xpm_file_to_image(index.mlx, "./test/eats5.xpm", &index.x, &index.y);
    index.img5 = mlx_xpm_file_to_image(index.mlx, "./test/grass.xpm", &index.x, &index.y);
   // check_event(&index, av[1]);
    //mlx_key_hook(index.win, key_hook, &index);
	mlx_loop_hook(index.win, key_hook, &index);
	mlx_loop(index.mlx);
}
