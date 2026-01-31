/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 01:50:25 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 01:52:19 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	change_color(t_fractol	*fractol)
{
	if (fractol->mlx)
		mlx_delete_image(fractol->mlx, fractol->img);
	fractol->color_shift += 1;
	if (fractol->color_shift > 8)
		fractol->color_shift = 1;
	change_color_in_struct(fractol);
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}

void	animation(t_fractol *fractol)
{
	fractol->jc.real = 0.7788 * cos(fractol->julia_angle);
	fractol->jc.imag = 0.7788 * sin(fractol->julia_angle);
	fractol->julia_angle += fractol->julia_speed;
	fractol->need_redraw = true;
}

void	ft_resize(int32_t width, int32_t height, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (fractol->img)
		mlx_delete_image(fractol->mlx, fractol->img);
	fractol->img = mlx_new_image(fractol->mlx, width, height);
	if (!fractol->img)
		return ;
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
	fractol->width = width;
	fractol->height = height;
	fractol->need_redraw = true;
}

void	calculation_colour(t_fractol *fractol, int i)
{
	double		t;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	t = (double)i / (double)MAX_ITER;
	t = pow(t, 0.9);
	fractol->brightness = 0.1 + 1.2 * t;
	r = (uint8_t)(fractol->color_r * fractol->brightness);
	g = (uint8_t)(fractol->color_g * fractol->brightness);
	b = (uint8_t)(fractol->color_b * fractol->brightness);
	a = fractol->color_a;
	fractol->color = (r << 24) | (g << 16) | (b << 8)
		| a;
}
