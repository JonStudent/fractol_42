/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:53:30 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:53:32 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_data *data, double i_rl, double i_ig, int itr)
{
	if (pow(data->n.rl, 2.0) + pow(data->n.ig, 2.0) >= 4 \
	|| ++itr == data->sttgs.mx_itr)
		return (itr);
	data->n.tmp = data->n.rl;
	data->n.rl = pow(data->n.rl, 2.0) - pow(data->n.ig, 2.0) + i_rl;
	data->n.ig = 2.0 * data->n.tmp * data->n.ig + i_ig;
	return (mandelbrot(data, i_rl, i_ig, itr));
}	

void	fractal(t_data *data, \
int (*set)(t_data *data, double i_rl, double i_ig, int itr))
{
	data->n.px_y = -1;
	while (++data->n.px_y < HEIGHT)
	{
		data->n.px_x = -1;
		while (++data->n.px_x < WIDTH)
			color(set(data, data->n.rl, data->n.ig, set_coords(data)), data);
	}
	mlx_put_image_to_window(data->img.mlx, data->img.win, data->img.img, 0, 0);
}
			// if(sqrt(pow(data->n.rl, 2.0) + pow(data->n.ig, 2.0)) <= 4.0)
			// 	my_mlx_pixel_put(data, data->n.px_x, data->n.px_y, 0x00FF0000);
			// if (!data->n.rl || !data->n.ig)
			// 	my_mlx_pixel_put(data, data->n.px_x, data->n.px_y, 0x00FFFFFF);
