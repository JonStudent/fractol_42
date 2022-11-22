#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 900
# define HEIGHT 900

//Pixels in one Centimeter
# define CM 38

typedef struct s_settings {
    int max_iter;
}               t_settings;

typedef struct	s_coords {
	int     pix_x;
    int     pix_y;
    double     real;
    double     imag;
    double     tmp;
}				t_coords;

typedef struct	s_img {
    void    *mlx;
    void    *win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
    int     lenght;
	int		endian;
}				t_img;

//Main  struct
typedef struct	s_data {
    t_settings  settings;
	t_img		img;
    t_coords    coords;
}				t_data;

//  AUX Functions

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	set_coordinates(t_data *data);

//  Sets Functions
void	mandelbrot(t_data *data);

#endif
