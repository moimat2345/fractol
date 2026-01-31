/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 01:45:59 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 02:18:44 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	start(t_fractol *render, char **argv)
{
	render->zoom = 300.0;
	render->offset_x = -1.90;
	render->offset_y = -1.40;
	render->color_shift = 0;
	render->color_r = 255;
	render->color_g = 255;
	render->color_b = 255;
	render->color_a = 255;
	render->width = 800;
	render->height = 800;
	render->animation = -1;
	render->julia_angle = 0.0;
	render->julia_speed = 0.02;
	if (argv[2] && argv[3])
	{
		render->julia_parm_x = atof(argv[2]);
		render->julia_parm_y = atof(argv[3]);
		render->jc.real = render->julia_parm_x;
		render->jc.imag = render->julia_parm_y;
	}
	render->fractal = what_fractal(argv[1]);
}

int	what_fractal(char *str)
{
	if (ft_strncmp(str, "mandelbrot", 11) == 0)
		return (1);
	else if (ft_strncmp(str, "julia", 6) == 0)
		return (2);
	else if (ft_strncmp(str, "tricorn", 8) == 0)
		return (3);
	else if (ft_strncmp(str, "burning_ship", 13) == 0)
		return (4);
	return (0);
}

void	prepar_julia(t_fractol *fractol)
{
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
}
