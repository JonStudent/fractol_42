#include "fractol.h"

int	main(void)
{
	t_data	data;

	data.img.mlx = mlx_init();
	data.img.win = mlx_new_window(data.img.mlx, WIDTH, HEIGHT, "Mandelbrot");
	data.img.img = mlx_new_image(data.img.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

	mandelbrot(&data);

	mlx_put_image_to_window(data.img.mlx,data.img.win, data.img.img, 0, 0);
	mlx_loop(data.img.mlx);
}
