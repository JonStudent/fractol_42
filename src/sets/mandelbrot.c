#include "../fractol.h"

int	recursive_mandlebrot(t_data *data, double init_real, double init_imag, int iter)
{
	if (pow(data->coords.real, 2.0) + pow(data->coords.imag, 2.0) >= 4 || ++iter == data->settings.max_iter)
		return (iter);
	data->coords.tmp = data->coords.real;
	data->coords.real = pow(data->coords.real, 2.0) - pow(data->coords.imag, 2.0) + init_real;
	data->coords.imag = 2.0 * data->coords.tmp * data->coords.imag + init_imag;
	return (recursive_mandlebrot(data, init_real, init_imag, iter));
}	

void	mandelbrot(t_data *data)
{
	int	iter;

	data->settings.max_iter = 150;

	data->coords.pix_y = -1;
	while (++data->coords.pix_y < HEIGHT)
	{
		data->coords.pix_x = -1;
		while (++data->coords.pix_x < WIDTH)
		{
			set_coordinates(data);
			iter = recursive_mandlebrot(data, data->coords.real, data->coords.imag, 0) * 255 / data->settings.max_iter;
			if (iter == 255)
				iter = 0;
			my_mlx_pixel_put(data, data->coords.pix_x, data->coords.pix_y, iter << 16 | iter << 8| iter);
		}
	}
}
			// if(sqrt(pow(data->coords.real, 2.0) + pow(data->coords.imag, 2.0)) <= 4.0)
			// 	my_mlx_pixel_put(data, data->coords.pix_x, data->coords.pix_y, 0x00FF0000);
			// if (!data->coords.real || !data->coords.imag)
			// 	my_mlx_pixel_put(data, data->coords.pix_x, data->coords.pix_y, 0x00FFFFFF);