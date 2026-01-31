/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:49:59 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 14:05:49 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	parser(int argc, char **argv, t_fractol *fractol)
{
	if (argc != 2 && argc != 4)
		return (input_message());
	if (what_fractal(argv[1]) == 0)
		return (input_message());
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
		{
			fractol->jc.real = -0.70176;
			fractol->jc.imag = -0.3842;
		}
		else if (!check_num(argv[2]) || !check_num(argv[3]))
			return (write(1, "Error\nInvalid parameters for Julia\n", 36));
		if (fractol->jc.real < -2.0 || fractol->jc.real > 2.0
			|| fractol->jc.imag < -2.0 || fractol->jc.imag > 2.0)
			return (write(1, "Error\nParameters to big for Julia\n", 36));
	}
	return (0);
}

void	loop_hook(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (fractol->need_redraw)
	{
		render_fractal(fractol);
		fractol->need_redraw = false;
	}
	if (fractol->animation == 1)
		animation(fractol);
}

void	fractol_main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof (t_fractol));
	if (!fractol)
		return ;
	valgrind_fix(fractol);
	if (parser(argc, argv, fractol) != 0)
		return ;
	start(fractol, argv);
	prepar_julia(fractol);
	fractol->mlx = mlx_init(fractol->width, fractol->height, argv[1], true);
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
	render_fractal(fractol);
	mlx_key_hook(fractol->mlx, ft_hook, fractol);
	mlx_resize_hook(fractol->mlx, ft_resize, fractol);
	mlx_scroll_hook(fractol->mlx, scroll_hook, fractol);
	mlx_loop_hook(fractol->mlx, loop_hook, fractol);
	mlx_loop(fractol->mlx);
	mlx_delete_image(fractol->mlx, fractol->img);
	mlx_terminate(fractol->mlx);
	free(fractol);
}

int	main(int argc, char **argv)
{
	char	*menu_av[8];
	int		menu_ac;

	if (argc == 1)
	{
		if (menu(&menu_ac, menu_av) != 0)
			return (write(1, "Error\nMenu input failed\n", 24));
		else
			fractol_main(menu_ac, menu_av);
	}
	else
		fractol_main(argc, argv);
	return (0);
}
