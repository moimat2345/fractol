/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 02:20:22 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 02:20:54 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	render_fractal(t_fractol	*fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < fractol->width)
	{
		fractol->y = 0;
		while (fractol->y < fractol->height)
		{
			if (fractol->fractal == 1)
				mandelbrot(fractol);
			else if (fractol->fractal == 2)
				julia(fractol);
			else if (fractol->fractal == 3)
				tricorn(fractol);
			else if (fractol->fractal == 4)
				burning_ship(fractol);
			fractol->y++;
		}
		fractol->x++;
	}
}

void	reset_fractal(t_fractol	*fractol)
{
	if (fractol->mlx)
		mlx_delete_image(fractol->mlx, fractol->img);
	fractol->zoom = 300.0;
	fractol->offset_x = -1.90;
	fractol->offset_y = -1.40;
	fractol->animation = -1;
	if (fractol->julia_parm_x != 0 && fractol->julia_parm_y != 0)
	{
		fractol->jc.real = fractol->julia_parm_x;
		fractol->jc.imag = fractol->julia_parm_y;
	}
	else
	{
		fractol->jc.real = -0.70176;
		fractol->jc.imag = -0.3842;
	}
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}
