/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:30:41 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 13:31:40 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color1(t_fractol	*fractol)
{
	if (fractol->color_shift == 1)
	{
		fractol->color_r = 255;
		fractol->color_g = 0;
		fractol->color_b = 0;
		fractol->color_a = 255;
	}
	else
	{
		fractol->color_r = 220;
		fractol->color_g = 90;
		fractol->color_b = 90;
		fractol->color_a = 255;
	}
}

void	color2(t_fractol	*fractol)
{
	if (fractol->color_shift == 3)
	{
		fractol->color_r = 90;
		fractol->color_g = 200;
		fractol->color_b = 120;
		fractol->color_a = 255;
	}
	else
	{
		fractol->color_r = 100;
		fractol->color_g = 140;
		fractol->color_b = 220;
		fractol->color_a = 255;
	}
}

void	color3(t_fractol	*fractol)
{
	if (fractol->color_shift == 5)
	{
		fractol->color_r = 235;
		fractol->color_g = 210;
		fractol->color_b = 120;
		fractol->color_a = 255;
	}
	else
	{
		fractol->color_r = 120;
		fractol->color_g = 210;
		fractol->color_b = 210;
		fractol->color_a = 255;
	}
}

void	color4(t_fractol	*fractol)
{
	if (fractol->color_shift == 7)
	{
		fractol->color_r = 200;
		fractol->color_g = 120;
		fractol->color_b = 200;
		fractol->color_a = 255;
	}
	else
	{
		fractol->color_r = 230;
		fractol->color_g = 180;
		fractol->color_b = 120;
		fractol->color_a = 255;
	}
}

void	change_color_in_struct(t_fractol	*fractol)
{
	if (fractol->color_shift == 1 || fractol->color_shift == 2)
		color1(fractol);
	else if (fractol->color_shift == 3 || fractol->color_shift == 4)
		color2(fractol);
	else if (fractol->color_shift == 5 || fractol->color_shift == 6)
		color3(fractol);
	else if (fractol->color_shift == 7 || fractol->color_shift == 8)
		color4(fractol);
	else
		fractol->color_shift = 0;
}
