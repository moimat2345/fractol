/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_help.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 02:49:13 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/19 13:22:31 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	input_message(void)
{
	ft_putstr("\n");
	ft_putstr("╔══════════════════════════════════════════════╗\n");
	ft_putstr("║               *  FRACT'OL  *                 ║\n");
	ft_putstr("╠══════════════════════════════════════════════╣\n");
	ft_putstr("║ Usage: ./fractol [fractal_name]              ║\n");
	ft_putstr("║ Example: ./fractol mandelbrot                ║\n");
	ft_putstr("╠──────────────────────────────────────────────╣\n");
	ft_putstr("║ Available Fractals:                          ║\n");
	ft_putstr("║   • Mandelbrot                               ║\n");
	ft_putstr("║   • Julia                                    ║\n");
	ft_putstr("║   • Tricorn                                  ║\n");
	ft_putstr("║   • Burning_Ship                             ║\n");
	ft_putstr("╠──────────────────────────────────────────────╣\n");
	ft_putstr("║ Controls:                                    ║\n");
	ft_putstr("║   ↑ ↓ ← → : Move                             ║\n");
	ft_putstr("║   Scroll     : Zoom In / Out                 ║\n");
	ft_putstr("║   F          : Switch Fractal                ║\n");
	ft_putstr("║   R          : Reset View                    ║\n");
	ft_putstr("║   C          : Change Color                  ║\n");
	ft_putstr("║   A          : Julia Animation               ║\n");
	ft_putstr("║   ESC        : Exit                          ║\n");
	ft_putstr("╚══════════════════════════════════════════════╝\n");
	ft_putstr("\n");
	return (1);
}

static void	menu_print(void)
{
	ft_putstr("\n");
	ft_putstr("╔═══════════════════════════════════════╗\n");
	ft_putstr("║          *  FRACT'OL MENU  *          ║\n");
	ft_putstr("╠═══════════════════════════════════════╣\n");
	ft_putstr("║  [1] Mandelbrot                       ║\n");
	ft_putstr("║  [2] Julia                            ║\n");
	ft_putstr("║  [3] Tricorn                          ║\n");
	ft_putstr("║  [4] Burning Ship                     ║\n");
	ft_putstr("╠═══════════════════════════════════════╣\n");
	ft_putstr("║  Choose a fractal and press ENTER     ║\n");
	ft_putstr("╚═══════════════════════════════════════╝\n> ");
}

void	prepar_menu_mjt(int *ac, char **av, int i)
{
	if (i == 1)
	{
		av[0] = av[0];
		av[1] = "mandelbrot\0";
		av[2] = NULL;
		*ac = 2;
	}
	else if (i == 2)
	{
		av[0] = av[0];
		av[1] = "julia\0";
		av[2] = NULL;
		*ac = 2;
	}
	else if (i == 3)
	{
		av[0] = av[0];
		av[1] = "tricorn\0";
		av[2] = NULL;
		*ac = 2;
	}
}

int	menu(int *ac, char **av)
{
	char	input[8];
	ssize_t	bytes_read;

	menu_print();
	bytes_read = read(0, input, 7);
	if (bytes_read <= 0)
		return (1);
	if (input[0] == '1')
		prepar_menu_mjt(ac, av, 1);
	else if (input[0] == '2')
		prepar_menu_mjt(ac, av, 2);
	else if (input[0] == '3')
		prepar_menu_mjt(ac, av, 3);
	else if (input[0] == '4')
	{
		av[0] = av[0];
		av[1] = "burning_ship\0";
		av[2] = NULL;
		*ac = 2;
	}
	else
		return (1);
	return (0);
}
