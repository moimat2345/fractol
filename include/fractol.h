/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:48:48 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 13:55:25 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../my_lib/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../my_lib/include/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

// Window dimensions
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 150

// complex number structure
typedef struct s_complex
{
	double	real;
	double	imag;
}				t_complex;

// main fractol structure
typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_complex	c;
	t_complex	z;
	t_complex	jc;
	double		julia_parm_x;
	double		julia_parm_y;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			fractal;
	int			color_shift;
	uint8_t		color_r;
	uint8_t		color_g;
	uint8_t		color_b;
	uint8_t		color_a;
	uint32_t	color;
	int			width;
	int			height;
	double		brightness;
	bool		need_redraw;
	int			x;
	int			y;
	int			animation;
	double		julia_angle;
	double		julia_speed;
}			t_fractol;

// fonctions declarations

// main.c
int				parser(int argc, char **argv, t_fractol *fractol);
void			loop_hook(void *param);

// utils.c
int				check_num(char *str);
double			ft_atof(char *str);
void			valgrind_fix(t_fractol *fractol);
void			valgrind_fix_part2(t_fractol *fractol);

// keys.c
void			change_fractal(t_fractol *fractol);
void			follow_zoom(t_fractol	*fractol, int x, int y, int zoom_in);
void			scroll_hook(double xdelta, double ydelta, void *param);
void			ft_hook(mlx_key_data_t key_data, void *mlx);

// init.c
void			start(t_fractol *render, char **argv);
int				what_fractal(char *str);
void			prepar_julia(t_fractol *fractol);

// image.c
void			change_color(t_fractol	*fractol);
void			animation(t_fractol *fractol);
void			ft_resize(int32_t width, int32_t height, void *param);
void			calculation_colour(t_fractol *fractol, int i);

// rendering.c
void			render_fractal(t_fractol	*fractol);
void			reset_fractal(t_fractol	*fractol);

// color.c
void			color1(t_fractol	*fractol);
void			color2(t_fractol	*fractol);
void			color3(t_fractol	*fractol);
void			color4(t_fractol	*fractol);
void			change_color_in_struct(t_fractol	*fractol);

// help.c
int				input_message(void);
int				menu(int *ac, char **av);

// fractols.c
int				mandelbrot(t_fractol *render);
int				julia(t_fractol	*render);
int				tricorn(t_fractol *fractol);
int				burning_ship(t_fractol *r);

#endif