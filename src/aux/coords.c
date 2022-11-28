/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:52:48 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:50 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//38 pixels in a cm
int	set_coords(t_data *data)
{
	data->n.rl = ((double)data->n.px_x - (double)WIDTH / 2.0) \
	/ (CM * (HEIGHT / 100)) - 0;
	data->n.ig = ((double)HEIGHT / 2.0 - (double)data->n.px_y) \
	/ (CM * (HEIGHT / 100));
	return (0);
}
