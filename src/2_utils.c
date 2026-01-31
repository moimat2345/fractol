/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 00:41:04 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 13:51:34 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	is_str_point(char *str)
{
	if (*str == '.')
		str++;
}

double	ft_atof(char *str)
{
	double	result;
	double	sign;
	double	decimal_place;

	result = 0.0;
	sign = 1.0;
	decimal_place = 0.1;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	is_str_point(str);
	while (*str >= '0' && *str <= '9')
	{
		result += (*str - '0') * decimal_place;
		decimal_place *= 0.1;
		str++;
	}
	return (result * sign);
}

int	check_num(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '.')
			return (0);
		str++;
		if (*str == '.')
			break ;
	}
	str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	valgrind_fix(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->img = NULL;
	fractol->c = (t_complex){0.0, 0.0};
	fractol->z = (t_complex){0.0, 0.0};
	fractol->jc = (t_complex){0.0, 0.0};
	fractol->julia_parm_x = 0.0;
	fractol->julia_parm_y = 0.0;
	fractol->zoom = 0.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->fractal = 0;
	valgrind_fix_part2(fractol);
}

void	valgrind_fix_part2(t_fractol *fractol)
{
	fractol->color_shift = 0;
	fractol->color_r = 0;
	fractol->color_g = 0;
	fractol->color_b = 0;
	fractol->color_a = 0;
	fractol->color = 0;
	fractol->width = 0;
	fractol->height = 0;
	fractol->brightness = 0.0;
	fractol->need_redraw = false;
	fractol->x = 0;
	fractol->y = 0;
	fractol->animation = 0;
	fractol->julia_angle = 0.0;
	fractol->julia_speed = 0.0;
}
