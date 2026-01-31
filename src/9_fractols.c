/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_fractols.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 02:27:38 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 13:26:57 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(t_fractol *r)
{
	int			i;
	double		temp;

	i = 0;
	r->z = (t_complex){0.0, 0.0};
	r->c.real = (r->x / r->zoom) + r->offset_x;
	r->c.imag = (r->y / r->zoom) + r->offset_y;
	while (i < MAX_ITER && r->z.real * r->z.real + r->z.imag * r->z.imag <= 4.0)
	{
		temp = ((r->z.real * r->z.real) - (r->z.imag * r->z.imag)) + r->c.real;
		r->z.imag = (2.0 * r->z.real * r->z.imag) + r->c.imag;
		r->z.real = temp;
		i++;
	}
	if (i == MAX_ITER)
		r->color = 0x0000FF;
	else
		calculation_colour(r, i);
	mlx_put_pixel(r->img, r->x, r->y, r->color);
	return (i);
}

int	julia(t_fractol	*fractol)
{
	int		n;
	double	tmp_real;

	n = 0;
	fractol->z.real = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->z.imag = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (++n < MAX_ITER)
	{
		tmp_real = (fractol->z.real * fractol->z.real)
			- (fractol->z.imag * fractol->z.imag);
		fractol->z.imag = 2.0 * fractol->z.real * fractol->z.imag;
		fractol->z.real = tmp_real + fractol->jc.real;
		fractol->z.imag += fractol->jc.imag;
		if ((fractol->z.real * fractol->z.real
				+ fractol->z.imag * fractol->z.imag) > 4)
			break ;
	}
	if (n == MAX_ITER)
		fractol->color = 0x0000FF;
	else
		calculation_colour(fractol, n);
	mlx_put_pixel(fractol->img, fractol->x, fractol->y, fractol->color);
	return (0);
}

int	tricorn(t_fractol *r)
{
	int			i;
	double		temp;

	i = 0;
	r->z = (t_complex){0.0, 0.0};
	r->c.real = (r->x / r->zoom) + r->offset_x;
	r->c.imag = (r->y / r->zoom) + r->offset_y;
	while (i < MAX_ITER && r->z.real * r->z.real + r->z.imag * r->z.imag <= 4.0)
	{
		temp = ((r->z.real * r->z.real) - (r->z.imag * r->z.imag)) + r->c.real;
		r->z.imag = (-2.0 * r->z.real * r->z.imag) + r->c.imag;
		r->z.real = temp;
		i++;
	}
	if (i == MAX_ITER)
		r->color = 0x0000FF;
	else
		calculation_colour(r, i);
	mlx_put_pixel(r->img, r->x, r->y, r->color);
	return (i);
}

int	burning_ship(t_fractol *r)
{
	int			i;
	double		temp;

	i = 0;
	r->z = (t_complex){0.0, 0.0};
	r->c.real = (r->x / r->zoom) + r->offset_x;
	r->c.imag = (r->y / r->zoom) + r->offset_y;
	while (i < MAX_ITER && r->z.real * r->z.real + r->z.imag * r->z.imag <= 4.0)
	{
		temp = ((r->z.real * r->z.real) - (r->z.imag * r->z.imag)) + r->c.real;
		r->z.imag = (2.0 * fabs(r->z.real) * fabs(r->z.imag)) + r->c.imag;
		r->z.real = temp;
		i++;
	}
	if (i == MAX_ITER)
		r->color = 0x0000FF;
	else
		calculation_colour(r, i);
	mlx_put_pixel(r->img, r->x, r->y, r->color);
	return (i);
}
