/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:58:27 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 02:21:10 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	change_fractal(t_fractol *fractol)
{
	if (fractol->fractal >= 4)
		fractol->fractal = 1;
	else
		fractol->fractal += 1;
}

void	follow_zoom(t_fractol	*fractol, int x, int y, int zoom_in)
{
	if (zoom_in == 1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x)
			- (x / (fractol->zoom * 1.42));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y)
			- (y / (fractol->zoom * 1.42));
		fractol->zoom *= 1.42;
	}
	else if (zoom_in == -1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x)
			- (x / (fractol->zoom / 1.42));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y)
			- (y / (fractol->zoom / 1.42));
		fractol->zoom /= 1.42;
	}
	else
		return ;
}

void	scroll_hook(double xdelta, double ydelta, void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)mlx;
	(void) xdelta;
	mlx_get_mouse_pos(fractol->mlx, &fractol->x, &fractol->y);
	if (ydelta > 0)
		follow_zoom(fractol, fractol->x, fractol->y, 1);
	else if (ydelta < 0)
		follow_zoom(fractol, fractol->x, fractol->y, -1);
	fractol->need_redraw = true;
}

void	ft_hook(mlx_key_data_t keydata, void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
		mlx_close_window(fractol->mlx);
	if (keydata.key == 265 && (keydata.action == 2 || keydata.action == 1))
		fractol->offset_y -= 0.00005 * fractol->zoom;
	if (keydata.key == 264 && (keydata.action == 2 || keydata.action == 1))
		fractol->offset_y += 0.00005 * fractol->zoom;
	if (keydata.key == 263 && (keydata.action == 2 || keydata.action == 1))
		fractol->offset_x -= 0.00005 * fractol->zoom;
	if (keydata.key == 262 && (keydata.action == 2 || keydata.action == 1))
		fractol->offset_x += 0.00005 * fractol->zoom;
	if (keydata.key == 67 && (keydata.action == 2 || keydata.action == 1))
		change_color(fractol);
	if (keydata.key == 82 && keydata.action == 1)
		reset_fractal(fractol);
	if (keydata.key == 70 && keydata.action == 1)
		change_fractal(fractol);
	if (keydata.key == 65 && keydata.action == 1)
		fractol->animation *= -1;
	fractol->need_redraw = true;
}
