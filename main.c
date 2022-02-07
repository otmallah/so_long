#include "so_long.h"

int main(void)
{
	t_long 	index;

	index.path7 = "./test/run1.xpm";
	index.path8 = "./test/run2.xpm";
	index.path9 = "./test/run3.xpm";
	index.path10 = "./test/run4.xpm";
    //index.fd = open("./test/test.ber", O_RDONLY);
	//index.str = get_next_line(index.fd);
	index.mlx = mlx_init();
	//index.a = ft_size_width();
	//index.i = ft_size_height();
	index.win = mlx_new_window(index.mlx, 1000, 650, " lo3ba za3ma ");
    index.img7 = mlx_xpm_file_to_image(index.mlx, index.path7, &index.x, &index.y);
    index.img8 = mlx_xpm_file_to_image(index.mlx, index.path8, &index.x, &index.y);
    index.img9 = mlx_xpm_file_to_image(index.mlx, index.path9, &index.x, &index.y);
    index.img10 = mlx_xpm_file_to_image(index.mlx, index.path10, &index.x, &index.y);
	mlx_put_image_to_window(index.mlx, index.win, index.img7, 0, 12);
   // check_event(&index);
    //mlx_key_hook(index.win, key_hook, &index);
	//system("leaks a.out");
	mlx_loop(index.mlx);
}
