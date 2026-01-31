/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 05:25:32 by mateon            #+#    #+#             */
/*   Updated: 2025/10/12 12:36:27 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		printed;

	printed = 0;
	nb = n;
	if (nb < 0)
	{
		printed += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		printed += ft_putnbr(nb / 10);
	printed += ft_putchar((nb % 10) + '0');
	return (printed);
}
