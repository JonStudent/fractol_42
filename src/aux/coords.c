#include "../fractol.h"

void	set_coordinates(t_data *data)
{
	data->coords.real = ((double)data->coords.pix_x - (double)WIDTH / 2.0 - (CM * (WIDTH / 250))) / (CM * (HEIGHT / 100)); //38 pixels in a cm
	data->coords.imag = ((double)HEIGHT / 2.0 - (double)data->coords.pix_y ) / (CM * (HEIGHT / 100)); //6 times escaled
}